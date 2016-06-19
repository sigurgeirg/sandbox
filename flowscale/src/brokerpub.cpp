
#include "../inc/brokerpub.h"

using namespace std;

BrokerPub::BrokerPub(const char* id) : mosquittopp(id){

}

BrokerPub::~BrokerPub() {

}

void BrokerPub::on_connect(int rc) {

    cout << "on_connect" << endl;

}

void BrokerPub::on_disconnect() {

    cout << "on_disconnect" << endl;
}


void BrokerPub::on_publish(uint16_t mid) {

    cout << "on_publish" << endl;
}
