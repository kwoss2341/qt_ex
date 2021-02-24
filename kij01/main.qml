import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0



Window {
    visible: true
    id: w1
    width: 640 //창의 넓이를 640
    height: 480 //창의 높이를 480
    title: qsTr("Hello World") //작업 표시줄의 제목을 Hello World로 출력


    /* 시그널 정의 */
    signal qmlSignal(int op, int mod)



        Rectangle
            {

                objectName: "r1"
                id: r1
                anchors.centerIn: parent
                width:100
                height:100

                   color:"white"

                   border.color: "black"
                   border.width: 5
                   Text {
                       id: t1
                       text: qsTr("option1 ")
                       anchors.centerIn: parent
                   }


             }

            Rectangle
               {
                   id:r12
                   width:300
                   height:100
                   anchors.left: r1.right
                   anchors.bottom:r1.bottom
                   color:"white"

                   border.color: "black"
                   border.width: 5

                   GroupBox {

                         RowLayout {
                             ExclusiveGroup { id: g1 }

                             RadioButton {
                                 objectName: "op11"           //option 1-1

                                 text: "option 1-1"
                                 exclusiveGroup: g1

                                 onClicked: {

                                     w1.qmlSignal(1,1);

                                 }


                             }
                             RadioButton {
                                 objectName: "op12"         //option 1-2


                                 text: "option 1-2"
                                 exclusiveGroup: g1
                                 onClicked: {

                                     w1.qmlSignal(1,2);

                                 }



                             }
                         }
                     }
               }

             Rectangle
             {
                   id:r3
                   width:100
                   height:100
                   anchors.left: r1.left
                   anchors.top:r1.bottom
                   color:"white"
                   border.color: "black"
                   border.width: 5
                   Text {
                       id: t3
                       text: qsTr("option2 ")
                       anchors.centerIn: parent
                   }
              }


             Rectangle
                {
                    id:r4
                    width:300
                    height:100
                    anchors.left: r3.right
                    anchors.bottom:r3.bottom
                    color:"white"
                    border.color: "black"
                    border.width: 5



                    GroupBox {

                          RowLayout {

                              ExclusiveGroup { id: g2 }
                              RadioButton {
                                  text: "option 2-1"            //option 2-1
                                  objectName: "op21"

                                  exclusiveGroup: g2

                                  onClicked: {

                                      w1.qmlSignal(2,1);

                                  }
                              }
                              RadioButton {
                                  objectName: "op22"            //option 2-2
                                  text: "option 2-2"
                                  exclusiveGroup: g2

                                  onClicked: {

                                      w1.qmlSignal(2,2);

                                  }
                              }
                          }
                      }
                }








}
