import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.3
import SerialNameList 1.0

import ByteGridViewModel 1.0



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


            Rectangle{
                id: rectangle
                color: "#1a1919"
                radius: 0
                border.color: "#0f0f0f"
                border.width: 0
                anchors.fill: view
            }

            Button{
                id:apander
                width: parent.width
                height: 30
                text: qsTr("Save bytes")

                onClicked: {
                    fileDialog.open()
                     //  modelViewByte.saveModelData()
                }
                FileDialog {
                    id: fileDialog
                    title: "Please choose a file"
                    folder: shortcuts.home
                    defaultSuffix: ".bin"
                    selectMultiple: false
                    selectExisting: false
                    selectFolder: false
                    nameFilters: "*.bin"
                    onAccepted: {
                        modelViewByte.saveModelData(fileDialog.fileUrl.toString())
                        fileDialog.close()
                    }
                    onRejected: {
                        console.log("Canceled")
                        fileDialog.close()
                    }
                    visible: false
                }

            }

                    ScrollView {
                        id: scrollView
                        //x: 0
                        //y: 0
                        anchors.top: apander.bottom
                        width: parent.width
                        height: parent.height-apander.height

                        clip: true
                        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                        ScrollBar.vertical.interactive: true

                        GridView{
                            id:gridV
                            flow: GridView.FlowLeftToRight
                            width: parent.width
                            y:90
                            height: 500
                            cacheBuffer: 200
                            leftMargin: 30
                            topMargin: 10
                            cellHeight: 30
                            cellWidth:60

                            delegate:Byte_View{}
                            model: ByteGridViewModel_qml{id:modelViewByte}
                        }



                    }

                }



            }
        }

    //}


//}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
