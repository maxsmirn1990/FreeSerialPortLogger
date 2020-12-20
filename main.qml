import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import SerialNameList 1.0
import Reader 1.0
import ByteGridViewModel 1.0


Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Логгер СОМ порта")
    Reader_qml{
        id:worker
        property int i: 0
        onM_readDataChanged:  {
            console.log("Пришела строка: "+m_readData)
            //        li.append(Byte_View)

        }

    }

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




//                Rectangle {
//                    id: rectangle1
//                    width: parent.width-10
//                    height: parent.height-5
//                    color: "#ffffff"
//                    radius: 10
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    visible: false


//                    ProgressBar{
//                        id:progres
//                        x: 32
//                        width: 0.9*view.width

//                        height:10
//                        visible: true
//                        anchors.top: parent.top
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        anchors.topMargin: 8
//                        hoverEnabled: false
//                        from:0
//                        to:1024
//                        value: 300
//                        background: Rectangle {
//                                implicitWidth: 200
//                                implicitHeight: 6
//                                color: "#6f836f"
//                                radius: 3
//                            }
//                        contentItem: Item {
//                                implicitWidth: 200
//                                implicitHeight: 4

//                                Rectangle {
//                                    width: progres.visualPosition * parent.width
//                                    height: parent.height
//                                    radius: 2
//                                    color: "#17a81a"
//                                }
//                            }
//                        }



//                    BusyIndicator{
//                        id:indikatorBusy
//                        x: 0
//                        width: rectangle1.width*0.2
//                        anchors.verticalCenter: parent.verticalCenter
//                        anchors.top: parent.top
//                        anchors.horizontalCenter: parent.horizontalCenter

//                        running: false
//                    }

            Button{
                id:apander
                width: parent.width
                height: 30
                text: qsTr("Add byte")

                onClicked: {
                       modelViewByte.addByte()
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
