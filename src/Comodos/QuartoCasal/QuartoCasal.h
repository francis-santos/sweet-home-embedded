#ifndef QUARTO_CASAL_H
#define QUARTO_CASAL_H

#include "../Comodo.h"

class QuartoCasalClass : public ComodoClass {
  public:
    static QuartoCasalClass* getInstance();
    virtual void setPinMode() override;
    virtual void resetPins() override;
    virtual void turnOnOffCentral(int state) override;
    virtual void turnOnOffCroicas(int state) override;
    virtual void turnOnOffLed(int state) override;
    virtual void turnOnOffCorredor(int state) override {};
    virtual void turnOnOffBox(int state) override {};
    virtual void turnOnOffAmericana(int state) override {};
    virtual void turnOnOffAreaServico(int state) override {};
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed();
    virtual int getStateCorredor() override {};
    virtual int getStateBox() override {};
    virtual int getStateAmericana() override {};
    virtual int getStateAreaServico() override {};
  private:
    static QuartoCasalClass* instance;
    int CENTRAL_D9232663;
    int CROICAS_D9232662;
    int LED_D9232656;
    QuartoCasalClass();
    virtual ~QuartoCasalClass();
};

#endif // QUARTO_CASAL_H
