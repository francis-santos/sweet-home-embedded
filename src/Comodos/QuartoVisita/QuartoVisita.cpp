#include "QuartoVisita.h"

QuartoVisitaClass* QuartoVisitaClass::instance = 0;

QuartoVisitaClass* QuartoVisitaClass::getInstance() {
  if (instance == 0) {
    instance = new QuartoVisitaClass();
  }
  return instance;
}

QuartoVisitaClass::QuartoVisitaClass() :
  CENTRAL_D9232654(17),
  CROICAS_D9232657(14)
{
  setPinMode();
  resetPins();
}

QuartoVisitaClass::~QuartoVisitaClass() {}

void QuartoVisitaClass::setPinMode() {
  pinMode(CENTRAL_D9232654, OUTPUT);
  pinMode(CROICAS_D9232657, OUTPUT);
}

void QuartoVisitaClass::resetPins() {
  digitalWrite(CENTRAL_D9232654, LOW);
  digitalWrite(CROICAS_D9232657, LOW);
}

void QuartoVisitaClass::turnOnOffCentral(int state) {
  digitalWrite(CENTRAL_D9232654, state);
}

void QuartoVisitaClass::turnOnOffCroicas(int state) {
  digitalWrite(CROICAS_D9232657, state);
}

int QuartoVisitaClass::getStateCentral() {
  return digitalRead(CENTRAL_D9232654);  
}

int QuartoVisitaClass::getStateCroicas() {
  return digitalRead(CROICAS_D9232657);  
}


