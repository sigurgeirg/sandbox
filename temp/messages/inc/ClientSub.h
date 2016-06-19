/*
 *  Created on: Jan 11, 2012
 *      Author: rene
This code is taken from Rene Lösch:
    https://lists.launchpad.net/mqtt-users/msg00063.html
    To: mqtt-users@xxxxxxxxxxxxxxxxxxx
    From: Rene Lösch <rene.loesch@xxxxxx>
    Date: Tue, 17 Jan 2012 15:04:02 +0100
    In-reply-to: <CAH7zdyf9zV3Ka=-EMgKDb5kRzdQefs4=Q3JG6BhzRykyC8xrsg@mail.gmail.com>

    For better understanding of how mosquitto can be used refer to:
    Header files mosquitto.h and mosquittopp.h which are located at /usr/include/mosquitt*.h
*/

#ifndef CLIENTSUB_H_
#define CLIENTSUB_H_

#include <mosquittopp.h>
#include <iostream>


class ClientSub : public mosquittopp::mosquittopp {

public:
    ClientSub(const char* id);
    virtual ~ClientSub();

private:
    uint16_t mid;

    void on_connect(int rc);
    void on_subscribe(uint16_t mid, int qos_count, const uint8_t *granted_qos);
    void on_message(const mosquitto_message *message);
    void print_error_connection(int rc);
};

#endif /* CLIENTSUB_H_ */
