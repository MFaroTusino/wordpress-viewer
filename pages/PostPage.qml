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
import WordpressViewer 1.0
import Qt.labs.shaders 1.0

Page {
    id: page
    property Post post
    onPostChanged: console.debug(post.comments)


    ShaderEffectItem {
        visible: SHADERS
        property variant source: ShaderEffectSource {
            sourceItem: flickAreaContainer
            hideSource: SHADERS
        }
        property int titleHeight: title.height + theme.paddingMedium
        property int separatorHeight: theme.paddingLarge

        property real _titleHeightRatio: flickArea.contentY > 0 ? 1 - titleHeight / height : 0
        property real _titleHeightAndSeparatorRatio: flickArea.contentY > 0
                                                     ? 1 - (titleHeight + separatorHeight) / height
                                                     : 0


        anchors.fill: flickAreaContainer

        fragmentShader: "
        varying highp vec2 qt_TexCoord0;
        uniform float _titleHeightRatio;
        uniform float _titleHeightAndSeparatorRatio;
        uniform sampler2D source;
        void main(void)
        {
            lowp vec4 textureColor = texture2D(source, qt_TexCoord0.st);
            gl_FragColor = smoothstep(_titleHeightRatio, _titleHeightAndSeparatorRatio,
                                      qt_TexCoord0.y)
                           * textureColor;
        }
        "
    }

    PostPageTitle {
        id: title
        visible: flickArea.contentY > 0 && SHADERS
        text: post.title
    }

    Item {
        id: flickAreaContainer
        anchors.fill: parent

        SilicaFlickable {
            id: flickArea
            anchors.fill: parent
            contentWidth: flickArea.width
            contentHeight: clonedTitle.height + label.height + 2 * theme.paddingMedium
                           + theme.paddingLarge
            flickableDirection: Flickable.VerticalFlick


            PostPageTitle {
                id: clonedTitle
                text: post.title
            }
            Label {
                id: label
                visible: !postHelper.loading
                width: flickArea.width
                text: postHelper.content
                wrapMode: Text.WordWrap
                color: theme.primaryColor
                anchors.left: parent.left; anchors.leftMargin: theme.paddingMedium
                anchors.right: parent.right; anchors.rightMargin: theme.paddingMedium
                anchors.top: clonedTitle.bottom
                anchors.topMargin: theme.paddingMedium + theme.paddingLarge
            }

            PullDownMenu {
                MenuItem {
                    text: "Author"
                    onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
                    }
                MenuItem{
                    text: "Share"
                    onClicked: pageStack.push(Qt.resolvedUrl("Share.qml"))
                }
                MenuItem{
                    text: "Comments"
                    onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
                }
            }

            PushUpMenu {
                MenuItem {
                    text: "Author"
                    onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
                    }
                MenuItem{
                    text: "Share"
                    onClicked: pageStack.push(Qt.resolvedUrl("Share.qml"))
                }
                MenuItem{
                    text: "Comments"
                    onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
                }
            }
        }
    }

    ProgressCircle {
        id: progress
        visible: postHelper.loading
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
