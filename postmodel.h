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

#ifndef POSTMODEL_H
#define POSTMODEL_H

#include <QtCore/QAbstractListModel>
#include <QtCore/QUrl>

class QNetworkAccessManager;
class QNetworkReply;
class SharedObjectsPool;
class Post;
class PostModel: public QAbstractListModel
{
    Q_OBJECT
    /**
     * @short Count
     */
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)
    Q_PROPERTY(QString error READ error NOTIFY errorChanged)
    Q_PROPERTY(QUrl api READ api WRITE setApi NOTIFY apiChanged)
    Q_PROPERTY(QString method READ method WRITE setMethod NOTIFY methodChanged)
public:
    enum PostModelRoles {
        PostRole
    };

    explicit PostModel(QObject *parent = 0);
    /**
     * @short Count
     * @return number of rows in this model.
     */
    int count() const;
    bool loading() const;
    QString error() const;
    QUrl api() const;
    QString method() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
public slots:
    void setApi(const QUrl &api);
    void setMethod(const QString &method);
    void load();
    void loadMore();
signals:
    void countChanged();
    void loadingChanged();
    void errorChanged();
    void apiChanged();
    void methodChanged();
    void loaded();
protected:
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    /**
     * @brief Role names
     * @return role names.
     */
    QHash<int, QByteArray> roleNames() const;
#endif
private:
    void setError(const QString &error);
    QNetworkAccessManager *m_networkAccessManager;
    QNetworkReply *m_reply;
    SharedObjectsPool *m_sharedObjectsPool;
    QList<Post *> m_posts;
    QString m_error;
    int m_page;
    int m_count;
    QUrl m_api;
    QString m_method;
private slots:
    void slotFinished();
};

#endif // POSTMODEL_H
