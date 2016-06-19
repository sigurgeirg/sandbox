#include "inc/ClientSub.h"
#include "inc/BrokerPub.h"
#include <cstring>

int main() {

/*  // This part is a MQTT Client setup

    int rc;
    ClientSub *mqttc = new ClientSub("cppclientsub");

    mqttc->lib_init();

    mqttc->connect("localhost", 1883, 60, true);

    do{
        rc = mqttc->loop(-1);
    }while(rc == MOSQ_ERR_SUCCESS);

    mqttc->disconnect();
    mqttc->lib_cleanup();
*/
    // This part is a MQTT Broker setup
    mosquittopp::mosquittopp::lib_init();

    int rc;
    char buf[1024] = "This is a test";
    BrokerPub *mqttb = new BrokerPub("  ");
    rc = mqttb->connect("localhost");

    if (MOSQ_ERR_SUCCESS == rc){

        rc = mqttb->loop();
        if (MOSQ_ERR_SUCCESS == rc){

            rc = mqttb->publish(NULL, "topic/test", strlen(buf), (uint8_t *)buf);
            rc = mqttb->loop();
        }
        rc = mqttb->disconnect();
        rc = mqttb->loop();
    }
    mosquittopp::mosquittopp::lib_cleanup();
    return 0;
}
