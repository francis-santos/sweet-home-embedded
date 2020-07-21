#include "QuartoCasal.h"

QuartoCasalClass* QuartoCasalClass::instance = 0;

QuartoCasalClass* QuartoCasalClass::getInstance() {
  if (instance == 0) {
    instance = new QuartoCasalClass();
  }
  return instance;
}

QuartoCasalClass::QuartoCasalClass() :
  CENTRAL_D9232663(5),
  CROICAS_D9232662(27),
  LED_D9232656(18)
{
  setPinMode();
  resetPins();
}

QuartoCasalClass::~QuartoCasalClass() {}

void QuartoCasalClass::setPinMode() {
  pinMode(CENTRAL_D9232663, OUTPUT);
  pinMode(CROICAS_D9232662, OUTPUT);
  pinMode(LED_D9232656, OUTPUT);
}

void QuartoCasalClass::resetPins() {
  digitalWrite(CENTRAL_D9232663, LOW);
  digitalWrite(CROICAS_D9232662, LOW);
  digitalWrite(LED_D9232656, LOW);
}

void QuartoCasalClass::turnOnOffCentral(int state) {
  digitalWrite(CENTRAL_D9232663, state);
}

void QuartoCasalClass::turnOnOffCroicas(int state) {
  digitalWrite(CROICAS_D9232662, state);
}

void QuartoCasalClass::turnOnOffLed(int state) {
  digitalWrite(LED_D9232656, state);
}

int QuartoCasalClass::getStateCentral() {
  return digitalRead(CENTRAL_D9232663);
}

int QuartoCasalClass::getStateCroicas() {
  return digitalRead(CROICAS_D9232662);
}

int QuartoCasalClass::getStateLed() {
  return digitalRead(LED_D9232656);
}
