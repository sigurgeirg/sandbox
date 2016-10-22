#include "../inc/mymessages.h"



MyMessages::MyMessages(QObject *parent) :
    QThread(parent)
{


}


MyMessages::~MyMessages()
{
    //

}



void MyMessages::sendMessage(QString message, const char *destination) {

    char buffer[1024] = "";
    size_t length = sizeof(message.toUtf8().data());

    memcpy(buffer, message.toUtf8().data(), length);

    mosqpp::lib_init();
    BrokerPub *mqttb = new BrokerPub("flow");
    rc = mqttb->connect("10.130.1.218");


    if (MOSQ_ERR_SUCCESS == rc){

        rc = mqttb->loop();
        if (MOSQ_ERR_SUCCESS == rc){

            rc = mqttb->publish(NULL, destination, strlen(buffer), (uint8_t *)buffer);
            rc = mqttb->loop();
        }
        rc = mqttb->disconnect();
        rc = mqttb->loop();
    }
    mosqpp::lib_cleanup();
}


void MyMessages::run() {

}
