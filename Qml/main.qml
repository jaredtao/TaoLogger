import QtQuick 2.0
import QtQuick.Controls 2.0
Item {
    Text {
        text: "TaoLogger " + fpsItem.fps + " fps"
        anchors.centerIn: parent
    }
    FPSItem {
        id: fpsItem
    }
}
