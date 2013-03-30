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
 
#ifndef AUTHOR_H
#define AUTHOR_H

#include <QtCore/QObject>
#include <QtCore/QUrl>
#include "jsonhelper_p.h"

class Author: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id NOTIFY idChanged)
    Q_PROPERTY(QString slug READ slug NOTIFY slugChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString firstName READ firstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName NOTIFY lastNameChanged)
    Q_PROPERTY(QString nickname READ nickname NOTIFY nicknameChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
public:
    explicit Author(QObject *parent = 0);
    static Author * create(const JsonObject &data, QObject *parent = 0);
    QString id() const;
    QString slug() const;
    QString name() const;
    QString firstName() const;
    QString lastName() const;
    QString nickname() const;
    QUrl url() const;
    QString description() const;
public slots:
    void update(const JsonObject &data);
signals:
    void idChanged();
    void slugChanged();
    void nameChanged();
    void firstNameChanged();
    void lastNameChanged();
    void nicknameChanged();
    void urlChanged();
    void descriptionChanged();
private:
    static bool isValid(const JsonObject &data);
    void setData(const JsonObject &data, bool signalChange = true);
    QString m_id;
    QString m_slug;
    QString m_name;
    QString m_firstName;
    QString m_lastName;
    QString m_nickname;
    QUrl m_url;
    QString m_description;
};

Q_DECLARE_METATYPE(Author*)

#endif // AUTHOR_H
