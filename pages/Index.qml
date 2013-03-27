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

import QtQuick 1.1
import Sailfish.Silica 1.0
import BlogViewer 1.0

Page {
    id: page

    PostModel {
        id: postModel
        api: API
        method: "get_recent_posts"
        Component.onCompleted: load()
        onErrorChanged: console.debug(error)
    }

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaListView {
        id: view
        anchors.fill: parent
        interactive: !postModel.loading
        opacity: !postModel.loading ? 1 : 0.5
        header: PageHeader {
            title: qsTr("Recent Posts")
        }
        model: postModel
        delegate: BackgroundItem {
            onClicked: pageStack.push(Qt.resolvedUrl("PostPage.qml"), {post: model.post})

            Label {
                textFormat : Text.RichText
                anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
                anchors.right: parent.right; anchors.rightMargin: theme.paddingLarge
                anchors.verticalCenter: parent.verticalCenter
                text: model.post.title
                truncationMode: TruncationMode.Fade
            }
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("About.qml"))
            }
            MenuItem{
                text: qsTr("Search")
                onClicked: pageStack.push(Qt.resolvedUrl("Search.qml"))
            }
            MenuItem{
                text: qsTr("Reload")
                onClicked: postModel.load()
            }
        }

        PushUpMenu {
            MenuItem {
                text: qsTr("More")
                onClicked: postModel.loadMore()
            }

            MenuItem {
                text: qsTr("Back to top")
                onClicked: view.scrollToTop()
            }
        }

        VerticalScrollDecorator {flickable: view}
    }

    ProgressCircle {
        id: progress
        visible: postModel.loading
        anchors.centerIn: parent
        value: postModel.progress
        onVisibleChanged: {
            progress.value = 0
        }

        Timer {
            interval: 16
            repeat: true
            running: progress.visible
            onTriggered: progress.value = (progress.value + 0.005) % 1.0
        }
    }
}


