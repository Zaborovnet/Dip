import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.5



Rectangle  {

   // id: win2
    //objectName: "window"
   // visible: true
    width: 512
    height: 512
    //property alias win: win2



/*Button {
    text: "Вывести карту"
    iconSource: ""
    tooltip: qsTr("")
    onClicked: {
        var component = Qt.createComponent("map3.qml");
        win = component.createObject(win2)
        win.show();
    }
}
*/
Connections {
        target: appCore  // Указываем целевое соединение
        /* Объявляем и реализуем функцию, как параметр
         * объекта и с имененем похожим на название сигнала
         * Разница в том, что добавляем в начале on и далее пишем
         * с заглавной буквы
         * */
        onTransmitNewText: {

            text1.text = text
        }
}

    Text {
        id: text1
        text: qsTr("Hello World.")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked:appCore.getOldText(text1.text)
    }
}


