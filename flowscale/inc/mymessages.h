#ifndef MYMESSAGES_H
#define MYMESSAGES_H

#include "clientsub.h"
#include "brokerpub.h"
#include <string>
#include <sstream>
#include <stdint.h>
#include <QThread>
#include <QDebug>

class MyMessages : public QThread
{
    Q_OBJECT
public:
    explicit MyMessages(QObject *parent = 0);
    ~MyMessages();

    void run();

    BrokerPub *mqttb;

private:
    int rc;

signals:


public slots:
   void sendMessage(QString, const char*);

};


#endif // MYMESSAGES_H
