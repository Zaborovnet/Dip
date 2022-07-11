import QtQuick.Controls 1.3
import QtWebKit 3.0
import QtQuick 2.7
import QtQuick.Window 2.2
import QtLocation 5.14

Window {
    id: win
    objectName: "window"
    visible: true
    width: 512
    height: 512


    Plugin {
          name: "osm"
          id: mapPlugin
          allowExperimental: true

         PluginParameter {name: "osm.mapping.providersrepository.address"; value: "https://tile.thunderforest.com/atlas/2/2/2.png?apikey=326f117bb12d43d8aae40aa382f44af1" }

         PluginParameter { name: "osm.mapping.highdpi_tiles"; value: true }


     }




    Map {
        id: map
        anchors.fill: parent
        activeMapType: map.supportedMapTypes[supportedMapTypes.length - 1]
        plugin: mapPlugin


}



    }

