#include "../inc/mymessages.h"



MyMessages::MyMessages(QObject *parent) :
    QThread(parent)
{
    dio = new MyDio(this);

}


MyMessages::~MyMessages()
{
    //
    delete dio;
}


void MyMessages::processReceivedWeight(int weightValueFromScale) {

    //if ( dio->falling[4] == 1	&& weightValueFromScale > 100) {

        char buffer[1024] = "";

        std::ostringstream convert;
        std::string sWeight;

        convert << weightValueFromScale;
        sWeight = convert.str();
        std::cout << "sWeight: " << sWeight << std::endl;
        memcpy(buffer, sWeight.c_str(), sizeof(sWeight.c_str())+1);

        mosqpp::lib_init();
        BrokerPub *mqttb = new BrokerPub("DynaScale");
        rc = mqttb->connect("127.0.0.1");

        if (MOSQ_ERR_SUCCESS == rc){

            rc = mqttb->loop();
            if (MOSQ_ERR_SUCCESS == rc){

                rc = mqttb->publish(NULL, "scale/weight", strlen(buffer), (uint8_t *)buffer);
                rc = mqttb->loop();
            }
            rc = mqttb->disconnect();
            rc = mqttb->loop();
        }
        mosqpp::lib_cleanup();
    //}
}


void MyMessages::run() {

}
