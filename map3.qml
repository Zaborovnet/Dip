import QtQuick.Controls 1.5
import QtWebKit 3.0
import QtQuick 2.7
import QtQuick.Window 2.2
import QtLocation 5.12

Rectangle {
    id: win
    objectName: "window"
    visible: true
    width: 650
    height: 230


    Plugin {
          name: "osm"
          id: mapPlugin
          allowExperimental: true



         PluginParameter {name: "osm.mapping.host"; value: "http://127.0.1.1/hot/1/0/0.png" }

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
        anchors.fill: parent
        activeMapType: map.supportedMapTypes[supportedMapTypes.length - 1]
        plugin: mapPlugin


}




    }

