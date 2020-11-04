import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Логгер СОМ порта")

    Grid {
        id: rootGrid
        anchors.fill: parent
        antialiasing: true
        topPadding: 2
        rows: 2
        columns: 1
        verticalItemAlignment: Grid.AlignTop

    Row{
        id:topPanel
        height: parent.height/4
        width: parent.width
        Rectangle{
            color: "#434141"
            anchors.fill: topPanel
        }
        }


    Row{
        id:view
        width: parent.width
        height: 500
        anchors.bottom: window.bottom
        Rectangle{
            color: "#434141"
            border.color: "#0f0f0f"
            anchors.fill: view
        }
    }

    }


}
