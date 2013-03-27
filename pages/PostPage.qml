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

   /* SilicaFlickable {
        id: pulleyMenu
        anchors.fill: parent
        anchors.bottom: flickArea.top; anchors.top: page.top
      */  PageHeader {
            id: pageHeader
             title: post.title
           /*
            Please look at making this truncated
            By making it page header outside flickable,
            the post will slide under the content and not above it
            */
        }

        // Pages referred to in pulley not yet implemented
  //    PullDownMenu {
    //        MenuItem {
      //          text: "Author"
    //            onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
    //            }
//            MenuItem{
//                text: "Comments"
//                onClicked: pageStack.push(Qt.resolvedUrl("Comments.qml"))
//            }

//            MenuItem{
//                text: "Share"
//                onClicked: pageStack.push(Qt.resolvedUrl("Share.qml"))
//            }
   // }


        // Tell SilicaFlickable the height of its content.
        //contentHeight: childrenRect.height
  //  }

 property Post post
/*
  This is currently set up so that there is a page header that
  is always visible, along with the pageStack indicators. The
  postContent is flickable and will move beneath the header on
  scroll.

  However, attempting to add pulley eithr makes the Text sit at (0,0) above the
  Stack indicator and header, or no content is displayed at all
  */
        Flickable{
        id: flickArea
        anchors.top: pageHeader.bottom; anchors.bottom: page.bottom
        anchors.left: page.left; anchors.leftMargin: theme.paddingLarge
        anchors.right: page.right; anchors.rightMargin: theme.paddingMedium
        contentWidth: flickArea.width; contentHeight: contentArea.height
        flickableDirection: Flickable.VerticalFlick
        clip: true
            Label{
                    id: contentArea
                    width: flickArea.width
                    text: post.content
                    wrapMode: Text.WordWrap
                    color: theme.primaryColor
                    font.pixelSize: theme.fontSizeLarge
                    anchors.left: parent.left; anchors.leftMargin: theme.paddingMedium
                    anchors.right: parent.right; anchors.rightMargin: theme.paddingMedium
                    anchors.top: parent.top; anchors.topMargin: theme.paddingMedium
                }
        }
    }


