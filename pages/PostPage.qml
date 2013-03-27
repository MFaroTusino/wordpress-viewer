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


