import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import SerialNameList 1.0
import Reader 1.0


Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Логгер СОМ порта")
    Reader_qml{
        id:worker
       onM_readDataChanged:  {
          //  console.log(m_readData)
           txt.placeholderText = m_readData.toString();
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
            color: "#434141"
            border.color: "#0f0f0f"
            anchors.fill: view

            ScrollView {
                id: scrollView
                anchors.fill: parent
                clip: true
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                ScrollBar.vertical.interactive: true

                ListView{
                    id:list_message
                    anchors.fill: parent
                    leftMargin: 5
                    rightMargin: 5
                    topMargin: 5
                    //columnSpacing: 3
                    //rowSpacing: 5
                    delegate: Byte_View
                    model: 10
                }
                ListModel{
                    id:modelViewByte
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                    ListElement{
                        txt: qsTr("0xFF")
                    }
                }



//                TextArea {
//                    id: txt
//                    anchors.fill: parent
//                    placeholderTextColor: "#000000"
//                    placeholderText: "Здесь будут данные с СОМ порта"
//                }

            }


        }
    }

  }


}
