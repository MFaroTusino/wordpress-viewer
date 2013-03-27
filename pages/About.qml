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
Page {
    id: page

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // Maybe not useful
//        PullDownMenu {
//            MenuItem {
//                text: "About"
//                //No onClicked action as this would cause recusrive browsing
//            }
//            MenuItem{
//                text: "Recent Posts"
//                onClicked: pageStack.pop()
//            }

//            MenuItem{
//                text: "Search"
//                onClicked: pageStack.replace(Qt.resolvedUrl("Search.qml"))
//            }
//        }


        // Tell SilicaFlickable the height of its content.
        contentHeight: childrenRect.height

    ListModel {
        id: modelContacts
        ListElement {
            elementID: "twitter"
            service: "Twitter"
            second: "@Q_Projects"
            url: "https://twitter.com/Q_Projects"

        }
        ListElement {
            elementID: "email"
            service: "Email"
            second: "email"
            url: "mailto://dev.mfarotusino@live.com.au"

        }
    }
    ListModel {
        id: modelThanks
        ListElement{
            elementID: "Lucien"
            name: "Lucien Xu"
            twitter: "@SfietKonstantin"
            url: "http://twitter/sfietkonstantin"
        }
    }

    PageHeader {
        id: header
        title: qsTr("About")
    }

    Label {
        id: createdBy
        anchors.top: header.bottom
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: qsTr("Created by: ")
        color: theme.primaryColor
        font.pixelSize: theme.fontSizeLarge
    }
    Label {
        id: creator
        anchors.top: createdBy.bottom; anchors.topMargin: theme.paddingSmall
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: "QProjects"
        color: theme.highlightColor
        font.pixelSize: theme.fontSizeSmall
    }
    Label {
        id: version
        anchors.top: creator.bottom; anchors.topMargin: theme.paddingLarge
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: qsTr("Version:")
        color: theme.primaryColor
        font.pixelSize: theme.fontSizeLarge
    }

   Label {
        id: versionNumber
        anchors.top: version.bottom; anchors.topMargin: theme.paddingSmall
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: "0.0.1~a1"
        color: theme.highlightColor
        font.pixelSize: theme.fontSizeSmall
        MouseArea {
            anchors.fill: versionNumber
            onClicked: pageStack.push(Qt.resolvedUrl("Changelog.qml"))
        }
    }


    Label {
        id: contactUs
        anchors.top: versionNumber.bottom; anchors.topMargin: theme.paddingLarge
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: qsTr("Contact us")
        color: theme.primaryColor
        font.pixelSize: theme.fontSizeLarge
    }

    Column {
        id: contacts
        width: page.width
        anchors.top: contactUs.bottom
        Repeater {
            model: modelContacts
            delegate: BackgroundItem {
                id: contactsBackground
                width: page.width
                onClicked: Qt.openUrlExternally(model.url)

                Label {
                    id: contactLabel
                    anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
                    anchors.verticalCenter: parent.verticalCenter
                    text: contactsBackground.pressed ? model.second : model.service
                    color: theme.highlightColor

                }
            }
        }
    }

    Label{
        id: specialThanks
        anchors.top: contacts.bottom
        anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
        text: qsTr("Special Thanks")
        color: theme.primaryColor
        font.pixelSize: theme.fontSizeLarge
    }

    Column {
        id: thanks
        width: page.width
        anchors.top: specialThanks.bottom
        Repeater {
            model: modelThanks
            delegate: BackgroundItem {
                id: thanksBackground
                width: page.width
                onClicked: Qt.openUrlExternally(model.url)

                Label {
                    id: thanksLabel
                    anchors.left: parent.left; anchors.leftMargin: theme.paddingLarge
                    anchors.verticalCenter: parent.verticalCenter
                    text: thanksBackground.pressed ? model.twitter : model.name
                    color: theme.highlightColor

                }
            }
        }
    }
}
}
