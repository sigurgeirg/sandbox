#!/usr/bin/python
 
import pynotify
import mosquitto  
 
#define what happens after connection
def on_connect(rc):
    print "Connected"

#On recipt of a message create a pynotification and show it
def on_message(msg):
    n = pynotify.Notification (msg.topic, msg.payload)
    #n.show ()
    print(msg.payload)
 
#create a broker
mqttc = mosquitto.Mosquitto("python_sub")

#define the callbacks
mqttc.on_message = on_message
mqttc.on_connect = on_connect

#connect
mqttc.connect("localhost", 1883, 60)

#subscribe to topic test
mqttc.subscribe("hello/world", 0)

#keep connected to broker
while mqttc.loop() == 0:
    pass



# On command line level run mosquitto Broker code by running:
# python mqttTest.py or
# mosquitto_sub -d -t hello/world
#
# On command line level run mosquitto client code by running:
# mosquitto_pub -d -t hello/world -m "Hello World"