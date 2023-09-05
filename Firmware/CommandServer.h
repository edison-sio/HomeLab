#ifndef COMMANDSERVER_H
#define COMMANDSERVER_H

#include <WiFi.h>
#include <PubSubClient.h>

// Design Command Server with MQTT protocol
class CommandServer
{
public:
    /**
     * Ctor.
    */
    CommandServer(char *name);

    /**
     * Set WiFi ssid and password.
     * @param ssid     WiFi SSID
     * @param password WiFi password
    */
   void setWiFi(char *ssid, char *password);

    /**
     * Connect WiFi.
     * @return    WiFi connection status message
     * @exception SSID and password are not set yet
     * @note      setWiFi() must be applied before this function
     *            is called
    */
    char *connectWiFi();

    /**
     * Set MQTT address and port.
     * @param brokerAddr Broker IP address
     * @param brokerPort Broker port
    */
    void setBroker(char *brokerAddr, uint8_t brokerPort);

    /**
     * Set MQTT broker username and password.
     * @param username Username to access MQTT broker
     * @param password Password of the user
    */
    void setBrokerCredential(char *username, char *password);

    /**
     * Connect to MQTT broker.
     * @return    MQTT broker connection status message
     * @exception broker address and port are not set or credentials are needed
     *            and not set
     * @note      setBroker() must be applied and setBrokerCredential() may be applied
     *            before this function is called
    */
    char *connectBroker();

    /**
     * Process command and respond
     * @param cmd Received command
     * @return    Result message
    */

    /**
     * Determine if the command server ready to run.
    */
    bool isReady();

    /**
     * Keep running the client by receiving messages
    */
    void loop();
    

    char *processCommand(char *cmd);
private:
    PubSubClient _client; // MQTT client to receive message
    char *_name;
    
    char *_ssid;
    char *_wifiPw;

}

#endif // COMMANDSERVER_H