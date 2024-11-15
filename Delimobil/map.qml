import QtQuick 2.12
import QtLocation 5.12
import QtPositioning 5.12

Rectangle {
    width: 400
    height: 600

    Plugin {
        id: mapPlugin
        name: "osm" // Используем OpenStreetMap как поставщика
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(55.751244, 37.618423) // Пример координат (Москва)
        zoomLevel: 14

        // Обработчик клика по карте
        MouseArea {
            anchors.fill: parent
            onClicked: {
                var coord = map.toCoordinate(Qt.point(mouse.x, mouse.y));
                coordinateSelected(coord); // Вызываем сигнал с координатами
            }
        }
    }

    signal coordinateSelected(var coordinate) // Сигнал для передачи координат
}
