#ifndef SETUP_MQTT_H
#define SETUP_MQTT_H

#include <PubSubClient.h>

extern PubSubClient client;

void setup_mqtt();
void reconnect_mqtt();
void publish_data(const char* topic, const char* payload);

#endif // SETUP_MQTT_H
