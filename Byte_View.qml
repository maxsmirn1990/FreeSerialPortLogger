import QtQuick 2.0
import ByteGridViewModel 1.0

Item {
    id:root
    Item {
        id: name
        width: 80
        height: 20
        Rectangle{
            id: rectangle
            color: "#d4fc79"
            anchors.fill: parent
            anchors.bottomMargin: 0
            anchors.rightMargin: 40
            enabled: false
        radius: 5

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#d4fc79"
            }

            GradientStop {
                position: 1
                color: "#96e6a1"
            }
        }
        Text {
            id: textByte
            font.bold: true
            font.pointSize: 9
            color: "#1a1919"
            text: display;
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: -5
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"

        }

        }
    }
}
