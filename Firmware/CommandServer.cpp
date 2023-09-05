#include "CommandServer.h"
#include <WiFi.h>
#include <PubSubClient.h>

// Implementation of class CommandServer

void CommandServer::CommandServer(char *name)
{
    WiFiClient wifiClient;
    _client = PubSubClient(wifiClient);
    _name = name;
}

void CommandServer::setWiFi(char *ssid, char *password)
{
    _ssid = ssid;
    _wifiPw = password;
}

char *CommandServer::connectWiFi()
{
    WiFi.begin(_ssid, _wifiPw);
}

void CommandServer::setBroker(char *brokerAddr, uint8_t brokerPort)
{
    _client.setServer(brokerAddr, brokerPort);
}

void CommandServer::setBrokerCredential(char *username, char *password)
{
    _client.setCredentials(username, password);
}

char *CommandServer::connectBroker()
{   
    _client.connect(_name);
    _client.subscribe('ESP32/Command')
}

bool CommandServer::isReady()
{
    return WiFi.status() == WL_CONNECTED && _client.connected()
}

char *CommandServer::processCommand(char *cmd)