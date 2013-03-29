/*
 * Copyright (C) 2013 Lucien XU <sfietkonstantin@free.fr>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 * * Neither the name of Jolla Ltd. nor the names of its contributors
 * may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 */

#include "posthelper.h"
#include <QtCore/QDebug>
#include <QtCore/QRegExp>
#include <QtCore/QStringList>

static const char * IMG_REGEXP = "(<img[^>]*>)";
static const char *URL_REGEXP = "src=(\"|')([^(\"|'']*)(\"|')";
static const char *WIDTH_REGEXP = "width=(\"|')([^(\"|'']*)(\"|')";
static const char *HEIGHT_REGEXP = "height=(\"|')([^(\"|'']*)(\"|')";

PostHelper::PostHelper(QObject *parent)
    : QObject(parent)
    , m_cacheManager(0)
    , m_screenWidth(0)
{
}

CacheManager * PostHelper::cacheManager() const
{
    return m_cacheManager;
}

int PostHelper::screenWidth() const
{
    return m_screenWidth;
}

QString PostHelper::content() const
{
    return m_content;
}

bool PostHelper::loading() const
{
    return !m_initialImages.empty();
}

void PostHelper::setCacheManager(CacheManager *cacheManager)
{
    if (m_cacheManager != cacheManager) {
        if (m_cacheManager) {
            disconnect(m_cacheManager, 0, this, 0);
        }

        m_cacheManager = cacheManager;
        connect(m_cacheManager, SIGNAL(requestFinished(QUrl,QString)),
                this, SLOT(slotRequestFinished(QUrl,QString)));
        emit cacheManagerChanged();
    }
}

void PostHelper::setScreenWidth(int screenWidth)
{
    if (m_screenWidth != screenWidth) {
        m_screenWidth = screenWidth;
        emit screenWidthChanged();
    }
}

void PostHelper::load(const QString &content)
{
    if (!m_cacheManager) {
        return;
    }

    if (!m_initialImages.isEmpty()) {
        return;
    }

    if (m_content == content) {
        return;
    }

    m_content = content;
    emit contentChanged();

    QRegExp imgRegExp (IMG_REGEXP);
    QRegExp urlRegExp (URL_REGEXP);

    // Extract images
    int currentIndex = 0;
    while (currentIndex != -1) {
        currentIndex = m_content.indexOf(imgRegExp, currentIndex);
        if (currentIndex != -1) {
            QString capturedString = imgRegExp.cap(1);

            // Extract URL
            if (capturedString.contains(urlRegExp)) {
                QUrl url = urlRegExp.cap(2);
                m_initialImages.insert(url, capturedString);
                m_cacheManager->request(url);
            }

            currentIndex += capturedString.count();
        }
    }

    if (!m_initialImages.isEmpty()) {
        emit loadingChanged();
    }
}

void PostHelper::slotRequestFinished(const QUrl &url, const QString &path)
{
    if (m_initialImages.isEmpty()) {
        return;
    }

    if (m_initialImages.contains(url)) {
        QString data = m_initialImages.value(url);

        // Fit to screen width
        QRegExp widthRegExp (WIDTH_REGEXP);
        QRegExp heightRegExp (HEIGHT_REGEXP);
        int width = -1;
        int height = -1;
        if (data.contains(widthRegExp)) {
            width = widthRegExp.cap(2).toInt();
        }

        if (data.contains(heightRegExp)) {
            height = heightRegExp.cap(2).toInt();
        }

        int recommandedScreenWidth = (int) ((float) m_screenWidth * 0.95);

        if (width != -1 && height != -1) {
            if (width > recommandedScreenWidth) {
                height = (int) ((float) recommandedScreenWidth / (float) width * (float) height);
                width = recommandedScreenWidth;
            }
        }

        if (width != -1) {
            if (width > recommandedScreenWidth) {
                width = recommandedScreenWidth;
            }
        }

        QString widthAndHeight = "";
        if (width != -1) {
            widthAndHeight.append(QString("width=\"%1\"").arg(width));
        }

        if (height != -1) {
            widthAndHeight.append(QString(" height=\"%1\"").arg(height));
        }

        QString finalData = QString("<img src=\"%1\" %2 alt=\"\" />").arg(path, widthAndHeight);

        m_initialImages.remove(url);
        m_content.replace(data, finalData);
        emit contentChanged();

        qDebug() << finalData;
    }

    if (m_initialImages.isEmpty()) {
        emit loadingChanged();
    }
}
