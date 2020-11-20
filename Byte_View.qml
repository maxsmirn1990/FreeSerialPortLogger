import QtQuick 2.0

Item {
    id:root
    property alias txt:textByte.text
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
//--------GRADIENT-------------------
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
//--------------------------------------------
        Text {
            id: textByte

            font.bold: false
            font.pointSize: 9
            color: "#434141"
            text: txt
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top

        }

        }
    }
}
