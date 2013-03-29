import QtQuick 1.1
import Sailfish.Silica 1.0

Label {
    anchors.top: parent.top; anchors.topMargin: theme.paddingMedium
    anchors.left: parent.left; anchors.leftMargin: theme.paddingMedium + 100
    anchors.right: parent.right; anchors.rightMargin: theme.paddingMedium
    wrapMode: Text.WordWrap
    font.pixelSize: theme.fontSizeLarge
    color: theme.highlightColor
    horizontalAlignment: Text.AlignRight
    textFormat: Text.RichText
}
