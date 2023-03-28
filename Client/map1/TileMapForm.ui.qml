import QtQuick 2.4
import QtLocation 5.12

Item {
    property alias map: map

    Map {
        id: map
        anchors.fill: parent

        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]
        zoomLevel: 1

        plugin: Plugin {
            id: osmPlugin
            name: "osm"
            PluginParameter {
                name: "osm.useragent"
                value: "qml app"
            }
            PluginParameter {
                name: "osm.mapping.host"
                value: "http://127.0.0.1:8080/"
            }
            PluginParameter {
                name: "osm.mapping.copyright"
                value: "qml app"
            }
            PluginParameter {
                name: "osm.mapping.providersrepository.disabled"
                value: true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
