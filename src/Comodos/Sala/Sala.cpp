#include "Sala.h"

SalaClass* SalaClass::instance = 0;

SalaClass* SalaClass::getInstance() {
  if (instance == 0) {
    instance = new SalaClass();
  }
  return instance;
}

SalaClass::SalaClass() :
  CENTRAL_D9232594(12),
  CROICAS_D9232665(16),
  LED_D9232655(13),
  CORREDOR_D9232664(2)
{
  setPinMode();
  resetPins();
}

SalaClass::~SalaClass() {}

void SalaClass::setPinMode() {
  pinMode(CENTRAL_D9232594, OUTPUT);
  pinMode(CROICAS_D9232665, OUTPUT);
  pinMode(LED_D9232655, OUTPUT);
  pinMode(CORREDOR_D9232664, OUTPUT);
}

void SalaClass::resetPins() {
  digitalWrite(CENTRAL_D9232594, LOW);
  digitalWrite(CROICAS_D9232665, LOW);
  digitalWrite(LED_D9232655, LOW);
  digitalWrite(CORREDOR_D9232664, LOW);
}

void SalaClass::turnOnOffCentral(int state) {
  digitalWrite(CENTRAL_D9232594, state);
}

void SalaClass::turnOnOffCroicas(int state) {
  digitalWrite(CROICAS_D9232665, state);
}

void SalaClass::turnOnOffLed(int state) {
  digitalWrite(LED_D9232655, state);
}

void SalaClass::turnOnOffCorredor(int state) {
  digitalWrite(CORREDOR_D9232664, state);
}

int SalaClass::getStateCentral() {
  return digitalRead(CENTRAL_D9232594);
}

int SalaClass::getStateCroicas() {
  return digitalRead(CROICAS_D9232665);
}

int SalaClass::getStateLed() {
  return digitalRead(LED_D9232655);
}

int SalaClass::getStateCorredor() {
  return digitalRead(CORREDOR_D9232664);
}

