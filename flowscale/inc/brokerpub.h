/*
 * BrokerPub.h
 *
 *  Created on: Jan 11, 2012
 *      Author: rene

http://m.blog.csdn.net/blog/a468903507/9242263
*/

#ifndef BROKERPUB_H_
#define BROKERPUB_H_

#include <../../usr/include/mosquittopp.h>
#include <iostream>
#include <stdint.h>


class BrokerPub : public mosqpp::mosquittopp {

public:
    BrokerPub(const char* id);
    virtual ~BrokerPub();

private:
    uint16_t mid;

    void on_connect(int rc);
    void on_disconnect();
    void on_publish(uint16_t mid);
};

#endif /* BROKERPUB_H_ */
