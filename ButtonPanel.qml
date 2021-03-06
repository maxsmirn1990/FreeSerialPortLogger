import QtQuick.Controls 2.12
import QtQuick 2.9
import SerialNameList 1.0
import SpeedList 1.0


    Rectangle{
        id:root
        color: "#434141"
        height: parent.height
        width: parent.width

    Grid{
        id:grid_root
        rows: 1
        columns: 3

        Row{
            id:combo
            width: root.width-5
            height: root.height/2-5
            topPadding: 5
            leftPadding: 5

           ComboBox{
                id:serialBox
                textRole: "display"

                editable: false
                rightPadding: 5
                width: root.width-10
                height: root.height/3


                model: SerialNameList_qml{

                       }

                displayText: display
                onCurrentIndexChanged:  {
                    serialBox.model.setPort(serialBox.currentIndex)
                }

            }
        }



         Column{
            id:refCol
            width: root.width/3
            height: root.height/2
            anchors.top: combo.bottom
            anchors.left: root.left
            leftPadding: 5

            Button{

                anchors.centerIn: parent.Center

                width: parent.width-10
                id:refbutton
                text: "Обновить"
               onClicked: {
                   serialBox.model.refresh()

               }

            }

        }
        Column{
            id:speedCol
            width: root.width/3
            height: root.height/2
            anchors.top: combo.bottom
            anchors.left: refCol.right

            //выбор скорости обмена данными
            ComboBox{
                id:speedCombo
                textRole: "display"
                anchors.centerIn: parent.Center
                width: speedCol.width-5
                model: SpeedList_qml{

                       }

                displayText: display
                onCurrentIndexChanged:  {
                     speedCombo.model.setSpeed(speedCombo.currentIndex)
                 }




            }
        }
        Column{
            id:startCol
            width: root.width/3
            height: root.height/2
            anchors.top: combo.bottom
            anchors.left: speedCol.right
            Button{
                id:startButton
                property bool status: false
                anchors.centerIn: parent.Center
                rightPadding: 5
                width: parent.width-5
                text: "Старт"
                onClicked:  {
                    speedCombo.model.setSpeed(speedCombo.currentIndex)
                    serialBox.model.setPort(serialBox.currentIndex)
                    if(!status){
                        startButton.text = "Стоп"
                        serialBox.enabled=false
                        status = !status
                        serialBox.model.startRead(serialBox.currentIndex)
                    } else {
                        startButton.text = "Старт"
                        serialBox.enabled =true
                        status = !status
                        serialBox.model.closePort()
                    }


                }


            }


     }



    }
  }



