#ifndef BANHEIRO_H
#define BANHEIRO_H

#include "../Comodo.h"

class BanheiroClass : public ComodoClass {
  public:
    static BanheiroClass* getInstance();
    virtual void setPinMode() override;
    virtual void resetPins() override;
    virtual void turnOnOffCentral(int state) override;
    virtual void turnOnOffCroicas(int state) override;
    virtual void turnOnOffBox(int state) override;
    virtual void turnOnOffLed(int state) override {};
    virtual void turnOnOffCorredor(int state) override {};
    virtual void turnOnOffAmericana(int state) override {};
    virtual void turnOnOffAreaServico(int state) override {};
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed() override {};
    virtual int getStateCorredor() override {};
    virtual int getStateBox();
    virtual int getStateAmericana() override {};
    virtual int getStateAreaServico() override {};
  private:
    static BanheiroClass* instance;
    int CENTRAL_D9232661;
    int CROICAS_D9232659;
    int BOX_D9232660;
    BanheiroClass();
    virtual ~BanheiroClass();
};

#endif // BANHEIRO_H
