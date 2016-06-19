/*
 * BrokerPub.h
 *
 *  Created on: Jan 11, 2012
 *      Author: rene
 */

#include <mosquittopp.h>
#include <iostream>

#ifndef BROKERPUB_H_
#define BROKERPUB_H_

class BrokerPub : public mosquittopp::mosquittopp {

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
