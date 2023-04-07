import QtQuick 2.0
import QtLocation 5.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Item
{
    id: osmMain
    property variant parameters

    function initializePlugin(pluginParameters)
    {
        var parameters = new Array;
        for(var prop in pluginParameters)
        {
            var parameter = Qt.createQmlObject('import QtLocation 5.12; PluginParameter{ name: "'+ prop + '"; value: "' + pluginParameters[prop] + '"}', map)
            parameters.push(parameter)
        }
        osmMain.parameters = parameters
        map.plugin = Qt.createQmlObject('import QtLocation 5.12; Plugin{ name: "osm";allowExperimental: true;parameters: osmMain.parameters }', osmMain)
    }

    Map {
        id: map
        anchors.fill: parent
        activeMapType: map.supportedMapTypes[supportedMapTypes.length - 1]
}
}
