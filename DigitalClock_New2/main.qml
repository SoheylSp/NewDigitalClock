import QtQuick 2.14
import QtQuick.Window 2.14

Window {

    visible : true
    width   : 640
    height  : 480
    title   : qsTr("DigitalClock")

    Rectangle{

        width           : parent.width/2
        height          : parent.width/2
        anchors.centerIn: parent
        color           : "purple"

        Text{

            anchors.centerIn:parent
            text: MyClock.hour + ":" + MyClock.minute + ":" +MyClock.second
            font.pointSize: 40
            color: "white"
        }

    }
}
