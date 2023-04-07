import QtQuick 2.4
import QtPositioning 5.12


TileMapForm {
  Connections {
    target: mainWindow

    /* устанавливаем слот на сигнал MainWindow::changeCoord */
    onChangeCoord: {
      map.center = QtPositioning.coordinate(lat, lon);
    }
  }
}
