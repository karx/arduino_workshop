#include "MQTTUtils.h"

MQTTUtils::MQTTUtils()
{
    this->espClient = new WiFiClient();
    this->client = new PubSubClient(*espClient);
}

void callback(char* topic, byte* payload, unsigned int length)
{
    Serial.print("Command from MQTT broker is : [");
    Serial.print(topic);
    Serial.print("\t");
    Serial.print((char*)payload);
    
    // if MQTT comes a 0 turn off LED on D2
    // PayloadUtils::parseAndExecutePayload(payload,length);

} //end callback

void MQTTUtils::reconnect() 
{
    // Loop until we're reconnected
    while (!this->client->connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Create a random client ID
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect
        //if you MQTT broker has clientID,username and password
        //please change following line to    if (client.connect(clientId,userName,passWord))
        if (this->client->connect(clientId.c_str()))
        {
            Serial.println("connected");
            //once connected to MQTT broker, subscribe command if any
            this->client->subscribe("kaaro/room");
        }
        else 
        {
            Serial.print("failed, rc=");
            Serial.print(this->client->state());
            Serial.println(" try again in 5 seconds");
            // Wait 6 seconds before retrying
            delay(6000);
        }
    }
} //end reconnect()

void MQTTUtils::setup()
{
    this->client->setServer(mqtt_server, 1883);
    this->client->setCallback(callback);
}

boolean MQTTUtils::connected()
{
    return this->client->connected();
}

boolean MQTTUtils::publish(char* topic,char* payload)
{
    return client->publish(topic,payload);
}