#ifndef COMODO_MAIN_H
#define COMODO_MAIN_H

#include "Sala/Sala.h"
#include "Cozinha/Cozinha.h"
#include "QuartoVisita/QuartoVisita.h"
#include "QuartoCasal/QuartoCasal.h"
#include "Banheiro/Banheiro.h"
#include "../OperatorFactory/OperatorFactory.h"
#include "../ClassFactory/ClassFactory.h"

class ComodoMainClass {
  public:
    void tunrOnOffLight(String sComodo, String sCircuito, int state);
    static ComodoMainClass* getInstance();
    void onOffCentral(ComodoClass* comodo, int state);
    void onOffCorredor(ComodoClass* comodo, int state);
    void onOffCroicas(ComodoClass* comodo, int state);
    void onOffLed(ComodoClass* comodo, int state);
    void onOffBox(ComodoClass* comodo, int state);
    void onOffAmericana(ComodoClass* comodo, int state);
    void onOffAreaServico(ComodoClass* comodo, int state);
    ComodoClass * getComodo(String sComodo);
    static String CENTRAL;
    static String CORREDOR;
    static String CROICAS;
    static String LED;
    static String BOX;
    static String AREA_SERVICO;
    static String AMERICANA;
  private:
    void carregarCircuitos();
    void carregarComodos();
    OperatorFactory<ComodoClass*> * operatorFactory;
    ClassFactory<ComodoClass*> * classFactory;    
    static ComodoMainClass* instance;
    ComodoMainClass();
    virtual ~ComodoMainClass();
};

#endif // COMODO_MAIN_H