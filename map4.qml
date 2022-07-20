import QtQuick.Controls 1.5
import QtWebKit 3.0
import QtQuick 2.7
import QtQuick.Window 2.2
import QtLocation 5.12

Window   {
    id: win2
    objectName: "window"
    visible: true
    width: 512
    height: 512
    property alias win: win2


    Plugin {
          name: "osm"
          id: mapPlugin
          allowExperimental: true



         PluginParameter {name: "osm.mapping.host"; value: "http://127.0.1.1/hot/6/0/0.png" }
         PluginParameter {
                         name: "osm.mapping.cache.directory"
                         value: "./mapCache/map"
                     }

         PluginParameter {
                         name:"osm.mapping.providersrepository.disable"
                         value:true
                     }
         PluginParameter { name: "osm.mapping.highdpi_tiles"; value: true }


     }




    Map {
        id: map
        plugin: mapPlugin
        anchors.fill: parent
        gesture.enabled: true

        zoomLevel: 20
        activeMapType: supportedMapTypes[7]




}
    Button{
            anchors.centerIn: parent;
            text: "Click Me!";
            anchors.verticalCenterOffset: 8
            anchors.horizontalCenterOffset: 9
            onClicked: {
                Map.color="lightgreen";
                Map.z=1;
                Map.visible=true;
            }
        }



    }

