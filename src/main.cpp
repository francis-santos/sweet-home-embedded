#include "esp_system.h"
#include "comodo/Comodo.hpp"
#include "comodo/Sala.hpp"
#include "Apartamento.hpp"
#include "iluminacao/Iluminacao.hpp"
#include "iluminacao/Croica.hpp"
#include "OTACode/OTACode.h" //class arduino ota
#include "Config/ConfigWifi.h"
#include "Comodos/ComodoMain.h"
#include <aREST.h>
#include <vector>

const int wdtTimeout = 3000;  //time in ms to trigger the watchdog
hw_timer_t *timer = NULL;

void IRAM_ATTR resetModule() {
  ets_printf("reboot\n");
  ESP.restart();
}

//ponteiro para a classe OTACode
OTACodeClass *ota;

//ponteiros para a classe dos comodos
ComodoMainClass *comodo;

// Create aREST instance
aREST rest = aREST();

// Declare functions to be exposed to the API
int comodoControl(String params);

void setup() {
  Apartamento * ap = new Apartamento();
  
  Comodo * comodoPai = new Sala();

  Iluminacao* iluminacao = Croica::getInstancia(comodoPai, 10);

  ap->setComodo(iluminacao);
  ap->getComodo()->ligarIluminacao();

  comodo = ComodoMainClass::getInstance();

  rest.function("comodo", comodoControl);

  rest.set_id("6891");
  rest.set_name("esp32-V1");

  Serial.begin(115200);
  delay(10);
  Serial.println("Booting...");

  initWifi();

  //Inicializando o ArduinoOTA
  ota = new OTACodeClass();
  ota->setLedStatusPort(23);
  ota->build();
  ota->start();

  Serial.println("Ready");

  digitalWrite(ota->getLedStatusPort(), HIGH);

  //inicializa o servidor
  server.begin();

  timer = timerBegin(0, 80, true); //timer 0, div 80
  timerAttachInterrupt(timer, &resetModule, true);
  timerAlarmWrite(timer, wdtTimeout * 1000, false); //set time in us
  timerAlarmEnable(timer); //enable interrupt
}

void loop() {
  timerWrite(timer, 0); //reset timer (feed watchdog)
  
  ota->watch();

  WiFiClient client = server.available();
  if (!client) { return; }

  //aguardando request
  while(!client.available())
    delay(10);

  rest.handle(client);

  delay(1);  
}

void split(String &s, const char* delim, std::vector<String> & v){
    // to avoid modifying original string
    // first duplicate the original string and return a char pointer then free the memory
    char * dup = strdup(s.c_str());
    char * token = strtok(dup, delim);
    while(token != NULL){
        v.push_back(token);
        // the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation
        token = strtok(NULL, delim);
    }
    free(dup);
}

// Custom function accessible by the API
int comodoControl(String params) {
  std::vector<String> vParams;
  split(params, ":", vParams);
  
  int statePin = 0;
  if (vParams[2].compareTo("STATE") != 0) {
    int state = vParams[2].toInt();
    comodo->tunrOnOffLight(vParams[0], vParams[1], state);
  } else {
    if (vParams[1].compareTo(ComodoMainClass::CENTRAL) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateCentral();
    } else if (vParams[1].compareTo(ComodoMainClass::CROICAS) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateCroicas();
    } else if (vParams[1].compareTo(ComodoMainClass::CORREDOR) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateCorredor();
    } else if (vParams[1].compareTo(ComodoMainClass::LED) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateLed();
    } else if (vParams[1].compareTo(ComodoMainClass::BOX) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateBox();
    } else if (vParams[1].compareTo(ComodoMainClass::AREA_SERVICO) == 0) {
      statePin = comodo->getComodo(vParams[0])->getStateAreaServico();
    } else {
      statePin = comodo->getComodo(vParams[0])->getStateAmericana();
    }
  }

  return statePin;
}
