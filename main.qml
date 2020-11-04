import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Логгер СОМ порта")

    Grid {
        id: rootGrid
        anchors.fill: parent
        antialiasing: true
        topPadding: 2
        spacing: 1
        rows: 2
        columns: 1

    Row{
        id:topPanel
        height: parent.height/4
        width: parent.width
        anchors.top: parent.top

        }


    Row{
        id:view
        anchors.top: topPanel.bottom
    }

    }


}
