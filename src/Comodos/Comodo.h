#pragma once
#include "Arduino.h"

class ComodoClass {
  public:
    ComodoClass() {};
    virtual ~ComodoClass() {};
    virtual void setPinMode();
    virtual void resetPins();
    virtual void turnOnOffCentral(int state);
    virtual void turnOnOffCroicas(int state);
    virtual void turnOnOffLed(int state);
    virtual void turnOnOffCorredor(int state);
    virtual void turnOnOffBox(int state);
    virtual void turnOnOffAmericana(int state);
    virtual void turnOnOffAreaServico(int state);
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed();
    virtual int getStateCorredor();
    virtual int getStateBox();
    virtual int getStateAmericana();
    virtual int getStateAreaServico();
};
