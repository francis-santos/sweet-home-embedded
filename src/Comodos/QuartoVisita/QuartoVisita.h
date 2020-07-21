#ifndef QUARTO_VISITA_H
#define QUARTO_VISITA_H

#include "../Comodo.h"

class QuartoVisitaClass : public ComodoClass {
  public:
    static QuartoVisitaClass* getInstance();
    virtual void setPinMode() override;
    virtual void resetPins() override;
    virtual void turnOnOffCentral(int state) override;
    virtual void turnOnOffCroicas(int state) override;
    virtual void turnOnOffLed(int state) override {};
    virtual void turnOnOffCorredor(int state) override {};
    virtual void turnOnOffBox(int state) override {};
    virtual void turnOnOffAmericana(int state) override {};
    virtual void turnOnOffAreaServico(int state) override {};
    virtual int getStateCentral();
    virtual int getStateCroicas();
    virtual int getStateLed() override {};
    virtual int getStateCorredor() override {};
    virtual int getStateBox() override {};
    virtual int getStateAmericana() override {};
    virtual int getStateAreaServico() override {};
  private:
    static QuartoVisitaClass* instance;
    int CENTRAL_D9232654;
    int CROICAS_D9232657;
    QuartoVisitaClass();
    virtual ~QuartoVisitaClass();
};

#endif // QUARTO_VISITA_H
