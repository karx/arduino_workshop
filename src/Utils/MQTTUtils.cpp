#include "MQTTUtils.h"

MQTTUtils::MQTTUtils()
{
    this->espClient = new WiFiClient();
    this->client = new PubSubClient(*espClient);
}

void callback(char* topic, byte* payload, unsigned int length)
{
    // Serial.print("Command from MQTT broker is : [");
    // Serial.print(topic);
    // Serial.print("\t");
    Serial.println((char*)payload);
    // if the number we get in payload matches One in our tambola ticket, Light up LED

    //hack to get first 2 chars as Int
    int payloadInt = (payload[0] - '0') * 10 + (payload[1] - '0');


    Serial.println(payloadInt);
    if(payloadInt == 13)
        digitalWrite(D1,HIGH);
    else if(payloadInt == 15)
        digitalWrite(D2,HIGH);
    else if(payloadInt == 18)
        digitalWrite(D3,HIGH);
    
    
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
            this->client->subscribe("fitso/admin");
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