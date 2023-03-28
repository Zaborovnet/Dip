import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtWebKit 3.0

Rectangle{

    WebView
    {
        id: webview
        anchors.fill: parent

        url: "qrc:/html/nnn.html"
    }
}
