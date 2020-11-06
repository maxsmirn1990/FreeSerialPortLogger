import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import SerialNameList 1.0


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
        height: parent.height/5
        width: parent.width


            ButtonPanel{
                id:panel
                height: parent.height
                width: parent.width
               }


        }


    Row{
        id:view
        width: parent.width
        height: parent.height*4/5
        anchors.bottom: window.bottom
        Rectangle{
            color: "#434141"
            border.color: "#0f0f0f"
            anchors.fill: view

            ScrollView {
                id: scrollView
                anchors.fill: parent

                TextArea {
                    id: txt
                    placeholderText: qsTr("Здесь будут данные с СОМ порта")
                }

            }


        }
    }

  }


}
