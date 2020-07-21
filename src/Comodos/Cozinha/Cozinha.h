#ifndef COZINHA_H
#define COZINHA_H

#include "../Comodo.h"

class CozinhaClass : public ComodoClass {
  public:
    static CozinhaClass* getInstance();
    virtual void setPinMode() override;
    virtual void resetPins() override;
    virtual void turnOnOffCentral(int state) override;
    virtual void turnOnOffCroicas(int state) override;
    virtual void turnOnOffAmericana(int state) override;
    virtual void turnOnOffAreaServico(int state) override;
    virtual void turnOnOffLed(int state) override {};
    virtual void turnOnOffCorredor(int state) override {};
    virtual void turnOnOffBox(int state) override {};
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed() override {};
    virtual int getStateCorredor() override {};
    virtual int getStateBox() override {};
    virtual int getStateAmericana();
    virtual int getStateAreaServico();
  private:
    static CozinhaClass* instance;
    int CENTRAL_D9232596;
    int CROICAS_D9232598;
    int AMERICANA_D9232595;
    int AREA_SERVICO_D9232597;
    CozinhaClass();
    virtual ~CozinhaClass();
};

#endif // COZINHA_H