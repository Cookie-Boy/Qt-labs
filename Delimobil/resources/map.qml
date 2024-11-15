import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Rectangle {
    width: 400
    height: 500

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(55.7558, 37.6176) // Центрируем карту на Москве

        signal coordinateSelected(var coordinate)

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                map.coordinateSelected(coord)
            }
        }

        MapQuickItem {
            id: marker
            anchorPoint.x: 12
            anchorPoint.y: 12
            coordinate: map.center
            sourceItem: Rectangle {
                width: 24
                height: 24
                color: "red"
                radius: 12
            }
        }

        onCoordinateSelected: marker.coordinate = coordinate
    }
}
