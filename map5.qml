import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12




Rectangle {
    id: win
    objectName: "window"
    visible: true
    width: 650
    height: 230


    property var currencyGetJsonData : "2"



    function myQmlFunction(msg: string) : string {
        console.log("Got message:", msg)
        currencyGetJsonData=msg;
        return currencyGetJsonData

    }

    Plugin {
          name: "osm"
          id: mapPlugin
          allowExperimental: true



         PluginParameter {name: "osm.mapping.host"; value: currencyGetJsonData}

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
    Button{

            anchors.centerIn: parent;
            text: currencyGetJsonData;
            anchors.verticalCenterOffset: 8
            anchors.horizontalCenterOffset: 9
            onClicked: {
                Map.color="lightgreen";
                Map.z=1;
                Map.visible=true;
            }
        }






//Item {
//    function myQmlFunction(msg: string) : string {
//        console.log("Got message:", msg)
//        msg2=msg
//        return "some return value"

//    }
//}
    }
