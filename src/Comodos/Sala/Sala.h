#ifndef SALA_H
#define SALA_H

#include "../Comodo.h"

class SalaClass : public ComodoClass {
  public:
    virtual void setPinMode() override;
    virtual void resetPins() override;
    virtual void turnOnOffCentral(int state) override;
    virtual void turnOnOffCroicas(int state) override;
    virtual void turnOnOffLed(int state) override;
    virtual void turnOnOffCorredor(int state) override;
    virtual void turnOnOffBox(int state) override {};
    virtual void turnOnOffAmericana(int state) override {};
    virtual void turnOnOffAreaServico(int state) override {};
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed();
    virtual int getStateCorredor();
    virtual int getStateBox() override {};
    virtual int getStateAmericana() override {};
    virtual int getStateAreaServico() override {};
    static SalaClass* getInstance();
  private:
    static SalaClass* instance;
    uint8_t CENTRAL_D9232594;
    uint8_t CROICAS_D9232665;
    uint8_t LED_D9232655;
    uint8_t CORREDOR_D9232664;
    SalaClass();
    virtual ~SalaClass(); 
};

#endif // SALA_H
