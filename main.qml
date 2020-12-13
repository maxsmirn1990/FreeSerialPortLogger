import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
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
            color: "#434141"
            border.color: "#0f0f0f"
            anchors.fill: view

            ProgressBar{
                id:progres
                width: 0.9*view.width

                height:10
                visible: true
                hoverEnabled: false
                anchors.horizontalCenter: parent.horizontalCenter
                from:0
                to:1024
                value: 512

            }
            BusyIndicator{
                id:indikatorBusy
                width: view.width
                height: view.height-progres.width
                anchors.top: progres.bottom
                anchors.topMargin: 5
                visible: true
            }

            ScrollView {
                id: scrollView
                anchors.fill: parent
                visible: false
                clip: true
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                ScrollBar.vertical.interactive: true

            GridView{
                id:gridV
                flow: GridView.FlowLeftToRight
                leftMargin: 30
                topMargin: 10
                cellHeight: 30
                cellWidth:60
                delegate:Byte_View{}
                model: ByteGridViewModel_qml{}
            }



            }



        }
    }

  }


}
