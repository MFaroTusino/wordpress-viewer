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

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/qdeclarative.h>
#include <iostream>

#include "sailfishapplication.h"
#include "author.h"
#include "cachemanager.h"
#include "comment.h"
#include "post.h"
#include "posthelper.h"
#include "postmodel.h"

static const char *NOSHADERS = "-noshaders";

void help() {
    std::cout << "Wordpress viewer" << std::endl;
    std::cout << "Usage: wordpress-viewer [-noshaders] api" << std::endl;
    std::cout << std::endl;
    std::cout << "  api: link to the JSON API of a blog." << std::endl;
    std::cout << "  -noshaders: disable shaders. Useful when there is no HW acceleration"
              << std::endl;
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(Sailfish::createApplication(argc, argv));
    app.data()->setOrganizationName("MFaroTusino");
    app.data()->setApplicationName("wordpress-viewer");

    int argumentCount = app.data()->arguments().count();
    if (argumentCount < 2 || argumentCount > 3) {
        help();
        return 0;
    }

    bool noShaders = false;
    QString api;
    QString firstArgument = app.data()->arguments().at(1);
    if (argumentCount == 2) {
        if (firstArgument == NOSHADERS) {
            help();
            return 0;
        } else {
            api = firstArgument;
        }
    } else {
        QString secondArgument = app.data()->arguments().at(2);
        if (firstArgument == NOSHADERS) {
            api = secondArgument;
            noShaders = true;
        } else if (secondArgument == NOSHADERS) {
            api = firstArgument;
            noShaders = true;
        } else {
            help();
            return 0;
        }
    }

    QScopedPointer<QDeclarativeView> view(Sailfish::createUninitializedView());

    // Register QML types
    qmlRegisterType<Author>("WordpressViewer", 1, 0, "Author");
    qmlRegisterType<CacheManager>("WordpressViewer", 1, 0, "CacheManager");
    qmlRegisterType<Comment>("WordpressViewer", 1, 0, "Comment");
    qmlRegisterType<Post>("WordpressViewer", 1, 0, "Post");
    qmlRegisterType<PostHelper>("WordpressViewer", 1, 0, "PostHelper");
    qmlRegisterType<PostModel>("WordpressViewer", 1, 0, "PostModel");

    // Read the changelog
    QFile file("/home/nemo/Documents/changelog");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line = in.readAll();
    view.data()->rootContext()->setContextProperty("CHANGELOG", line);
    view.data()->rootContext()->setContextProperty("API", api);
    view.data()->rootContext()->setContextProperty("SHADERS", !noShaders);

    Sailfish::initializeView(view.data(), "main.qml");
    Sailfish::showView(view.data());

    return app->exec();
}
