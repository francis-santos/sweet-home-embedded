#include <ArduinoOTA.h> //lib que permite gravação via wifi

class OTACodeClass {
  public:
    OTACodeClass();
    void setHostname(const char * hostname);
    void setPassword(const char * password);
    void setEncrypt(bool encrypt);
    void setLedStatusPort(int port);
    int getLedStatusPort();
    void build();
    void start();
    void watch();
  private:
    const char * _hostname;
    const char * _password;    
    bool _encrypt;
    int _ledStatusPort;
    void _startOTA();
    void _endOTA();
    void _progressOTA(unsigned int progress, unsigned int total);
    void _errorOTA(ota_error_t error);
};
