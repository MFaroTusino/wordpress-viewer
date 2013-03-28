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



Rectangle {
     //property Post post
    color: "#33CCFF"


    PostModel {
        id: postModel
        api: API
        method: "get_recent_posts"
        Component.onCompleted: load()
        onErrorChanged: console.debug(error)
    }


    anchors.fill: parent
    Image {
        anchors.centerIn: parent
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        id: coverImage
        source: "/home/nemo/Pictures/utp.jpg" //featured image from post
    }

    Label {
        id: label
        color: theme.highlightColor
        font.pixelSize: theme.fontSizeLarge
        anchors.left: parent.left
        //text: post.title
        wrapMode: Text.Wrap
        width: parent.width
    }

    CoverActionList {
        id: coverAction
        CoverAction{
            id: refreshPosts
           // iconSource: refreshicon
            //onClicked: postModel.load()
        }

        CoverAction {
            id: nextPost

            iconSource: "image://theme/icon-cover-next"
           //onTriggered: nextPost image
        }
    }
}


