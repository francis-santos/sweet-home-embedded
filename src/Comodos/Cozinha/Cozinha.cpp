#include "Cozinha.h"

CozinhaClass* CozinhaClass::instance = 0;

CozinhaClass* CozinhaClass::getInstance() {
  if (instance == 0) {
    instance = new CozinhaClass();
  }
  return instance;
}

CozinhaClass::CozinhaClass() :
  CENTRAL_D9232596(26),
  CROICAS_D9232598(19),
  AMERICANA_D9232595(25),
  AREA_SERVICO_D9232597(21)
{
  setPinMode();
  resetPins();
}

CozinhaClass::~CozinhaClass() {}

void CozinhaClass::setPinMode() {
  pinMode(CENTRAL_D9232596, OUTPUT);
  pinMode(CROICAS_D9232598, OUTPUT);
  pinMode(AMERICANA_D9232595, OUTPUT);
  pinMode(AREA_SERVICO_D9232597, OUTPUT);
}

void CozinhaClass::resetPins() {
  digitalWrite(CENTRAL_D9232596, LOW);
  digitalWrite(CROICAS_D9232598, LOW);
  digitalWrite(AMERICANA_D9232595, LOW);
  digitalWrite(AREA_SERVICO_D9232597, LOW);
}

void CozinhaClass::turnOnOffCentral(int state) {
  digitalWrite(CENTRAL_D9232596, state);
}

void CozinhaClass::turnOnOffCroicas(int state) {
  digitalWrite(CROICAS_D9232598, state);
}

void CozinhaClass::turnOnOffAmericana(int state) {
  digitalWrite(AMERICANA_D9232595, state);
}

void CozinhaClass::turnOnOffAreaServico(int state) {
  digitalWrite(AREA_SERVICO_D9232597, state);
}

int CozinhaClass::getStateCentral() {
  return digitalRead(CENTRAL_D9232596);
}

int CozinhaClass::getStateCroicas() {
  return digitalRead(CROICAS_D9232598);
}

int CozinhaClass::getStateAmericana() {
  return digitalRead(AMERICANA_D9232595);
}

int CozinhaClass::getStateAreaServico() {
  return digitalRead(AREA_SERVICO_D9232597);
}

