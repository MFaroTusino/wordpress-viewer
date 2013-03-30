/*
 * Copyright (C) 2013 Lucien XU <sfietkonstantin@free.fr>
 * Copyright (C) 2013 Michael Faro-Tusino <dev.mfarotusino@live.com.au>
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
 
#include "comment.h"
#include "datetimeformat_p.h"

static const char *COMMENT_ID_KEY = "id";
static const char *COMMENT_NAME_KEY = "name";
static const char *COMMENT_URL_KEY = "url";
static const char *COMMENT_DATE_KEY = "date";
static const char *COMMENT_CONTENT_KEY = "content";
static const char *COMMENT_PARENT_KEY = "parent";

Comment::Comment(QObject *parent)
    : QObject(parent)
{
}

Comment * Comment::create(const JsonObject &data, QObject *parent)
{
    if (!isValid(data)) {
        return 0;
    }
    Comment * comment = new Comment(parent);
    comment->setData(data, false);
    return comment;
}

QString  Comment::id() const
{
    return m_id;
}

QString  Comment::name() const
{
    return m_name;
}

QString  Comment::url() const
{
    return m_url;
}

QDateTime  Comment::date() const
{
    return m_date;
}

QString  Comment::content() const
{
    return m_content;
}

QString  Comment::parent() const
{
    return m_parent;
}

void Comment::update(const JsonObject &data)
{
    if (!isValid(data)) {
        return;
    }
    setData(data);
}

bool Comment::isValid(const JsonObject &data)
{
    if (!data.contains(COMMENT_ID_KEY)) {
        return false;
    }
    if (!data.contains(COMMENT_NAME_KEY)) {
        return false;
    }
    if (!data.contains(COMMENT_URL_KEY)) {
        return false;
    }
    if (!data.contains(COMMENT_DATE_KEY)) {
        return false;
    }
    if (!data.contains(COMMENT_CONTENT_KEY)) {
        return false;
    }
    if (!data.contains(COMMENT_PARENT_KEY)) {
        return false;
    }
    return true;
}

void Comment::setData(const JsonObject &data, bool signalChange)
{
    QString id = JSON_GET_STRING(data.value(COMMENT_ID_KEY));
    QString name = JSON_GET_STRING(data.value(COMMENT_NAME_KEY));
    QString url = JSON_GET_STRING(data.value(COMMENT_URL_KEY));
    QString dateString = JSON_GET_STRING(data.value(COMMENT_DATE_KEY));
    QDateTime date = QDateTime::fromString(dateString, DATE_TIME_FORMAT);
    QString content = JSON_GET_STRING(data.value(COMMENT_CONTENT_KEY));
    QString parent = JSON_GET_STRING(data.value(COMMENT_PARENT_KEY));
    if (m_id != id) {
        m_id = id;
        if (signalChange) {
            emit idChanged();
        }
    }
    if (m_name != name) {
        m_name = name;
        if (signalChange) {
            emit nameChanged();
        }
    }
    if (m_url != url) {
        m_url = url;
        if (signalChange) {
            emit urlChanged();
        }
    }
    if (m_date != date) {
        m_date = date;
        if (signalChange) {
            emit dateChanged();
        }
    }
    if (m_content != content) {
        m_content = content;
        if (signalChange) {
            emit contentChanged();
        }
    }
    if (m_parent != parent) {
        m_parent = parent;
        if (signalChange) {
            emit parentChanged();
        }
    }
}
