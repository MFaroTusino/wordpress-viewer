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
 
#ifndef COMMENT_H
#define COMMENT_H

#include <QtCore/QDateTime>
#include <QtCore/QObject>
#include "jsonhelper_p.h"

class Comment: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString  id READ id NOTIFY idChanged)
    Q_PROPERTY(QString  name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString  url READ url NOTIFY urlChanged)
    Q_PROPERTY(QDateTime  date READ date NOTIFY dateChanged)
    Q_PROPERTY(QString  content READ content NOTIFY contentChanged)
    Q_PROPERTY(QString  parent READ parent NOTIFY parentChanged)
public:
    explicit Comment(QObject *parent = 0);
    static Comment * create(const JsonObject &data, QObject *parent = 0);
    QString  id() const;
    QString  name() const;
    QString  url() const;
    QDateTime  date() const;
    QString  content() const;
    QString  parent() const;
public slots:
    void update(const JsonObject &data);
signals:
    void idChanged();
    void nameChanged();
    void urlChanged();
    void dateChanged();
    void contentChanged();
    void parentChanged();
private:
    static bool isValid(const JsonObject &data);
    void setData(const JsonObject &data, bool signalChange = true);
    QString m_id;
    QString m_name;
    QString m_url;
    QDateTime m_date;
    QString m_content;
    QString m_parent;
};

Q_DECLARE_METATYPE(Comment*)

#endif // COMMENT_H
