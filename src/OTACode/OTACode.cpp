#include <ArduinoOTA.h> //lib que permite gravação via wifi
#include "OTACode.h"

OTACodeClass::OTACodeClass() :
  _hostname("myHouse"),
  _password("689101"),
  _encrypt(false)
{
}

void OTACodeClass::setHostname(const char * hostname) {
  _hostname = hostname;
}

void OTACodeClass::setPassword(const char * password) {
  _password = password;
}

void OTACodeClass::setEncrypt(bool encrypt) {
  _encrypt = encrypt;
}

void OTACodeClass::setLedStatusPort(int port) {
  _ledStatusPort = port;
}

int OTACodeClass::getLedStatusPort() {
  return _ledStatusPort;
}

void OTACodeClass::_startOTA() {
  String type;

  if (ArduinoOTA.getCommand() == U_FLASH) {
    type = "flash";
  } else {
    type = "filesystem";
  }

  Serial.println("Start updating " + type);

  digitalWrite(_ledStatusPort, HIGH);
  delay(300);
  digitalWrite(_ledStatusPort, LOW);
  delay(300);
  digitalWrite(_ledStatusPort, HIGH);
  delay(300);
  digitalWrite(_ledStatusPort, LOW);
  delay(300);
  
}

void OTACodeClass::_endOTA() {
  Serial.println("\nEnd");
}

void OTACodeClass::_progressOTA(unsigned int progress, unsigned int total) {
  Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
}

void OTACodeClass::_errorOTA(ota_error_t error) {
  Serial.printf("Error[%u]: ", error);

  if (error == OTA_AUTH_ERROR) {
    Serial.println("Auth Failed");
  } else if (error == OTA_BEGIN_ERROR) {
    Serial.println("Begin Failed");
  } else if (error == OTA_CONNECT_ERROR) {
    Serial.println("Connect Failed");
  } else if (error == OTA_RECEIVE_ERROR) {
    Serial.println("Receive Failed");
  } else if (error == OTA_END_ERROR) {
    Serial.println("End Failed");
  } else {
    Serial.println("Other error occured");
  }
}

void OTACodeClass::build() {
  pinMode(_ledStatusPort, OUTPUT);
  
  // Define o hostname
  ArduinoOTA.setHostname(_hostname);

  if(!_encrypt) {
    // Define a senha
    ArduinoOTA.setPassword(_password);
  } else {
    // Define uma senha criptografada em MD5
    ArduinoOTA.setPasswordHash(_password);
  }
  
  ArduinoOTA.onStart(std::bind(&OTACodeClass::_startOTA, this));

  ArduinoOTA.onEnd(std::bind(&OTACodeClass::_endOTA, this));

  auto fnOnProgress = std::bind(
    &OTACodeClass::_progressOTA,
    this,
    std::placeholders::_1,
    std::placeholders::_2
  );
  ArduinoOTA.onProgress(fnOnProgress);

  auto fnOnError = std::bind(
    &OTACodeClass::_errorOTA,
    this,
    std::placeholders::_1
  );
  ArduinoOTA.onError(fnOnError);
  
}

void OTACodeClass::start() {
  ArduinoOTA.begin();
}

void OTACodeClass::watch() {
  ArduinoOTA.handle();
}


