#include "Banheiro.h"

BanheiroClass* BanheiroClass::instance = 0;

BanheiroClass* BanheiroClass::getInstance() {
  if (instance == 0) {
    instance = new BanheiroClass();
  }
  return instance;
}

BanheiroClass::BanheiroClass() :
  CENTRAL_D9232661(33),
  CROICAS_D9232659(22),
  BOX_D9232660(32)
{
  setPinMode();
  resetPins();
}

BanheiroClass::~BanheiroClass() {}

void BanheiroClass::setPinMode() {
  pinMode(CENTRAL_D9232661, OUTPUT);
  pinMode(CROICAS_D9232659, OUTPUT);
  pinMode(BOX_D9232660, OUTPUT);
}

void BanheiroClass::resetPins() {
  digitalWrite(CENTRAL_D9232661, LOW);
  digitalWrite(CROICAS_D9232659, LOW);
  digitalWrite(BOX_D9232660, LOW);
}

void BanheiroClass::turnOnOffCentral(int state) {
  digitalWrite(CENTRAL_D9232661, state);
}

void BanheiroClass::turnOnOffCroicas(int state) {
  digitalWrite(CROICAS_D9232659, state);
}

void BanheiroClass::turnOnOffBox(int state) {
  digitalWrite(BOX_D9232660, state);
}

int BanheiroClass::getStateCentral() {
  return digitalRead(CENTRAL_D9232661);
}

int BanheiroClass::getStateCroicas() {
  return digitalRead(CROICAS_D9232659);
}

int BanheiroClass::getStateBox() {
  return digitalRead(BOX_D9232660);
}

