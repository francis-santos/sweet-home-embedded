#include "ComodoMain.h"

String ComodoMainClass::CENTRAL = "CENTRAL";
String ComodoMainClass::CORREDOR = "CORREDOR";
String ComodoMainClass::CROICAS = "CROICAS";
String ComodoMainClass::LED = "LED";
String ComodoMainClass::BOX = "BOX";
String ComodoMainClass::AREA_SERVICO = "AREA_SERVICO";
String ComodoMainClass::AMERICANA = "AMERICANA";

ComodoMainClass* ComodoMainClass::instance = 0;

ComodoMainClass* ComodoMainClass::getInstance() {
  if (instance == 0) {
    instance = new ComodoMainClass();
  }
  return instance;
}

ComodoMainClass::ComodoMainClass() {
  carregarComodos();
  carregarCircuitos();
}

ComodoMainClass::~ComodoMainClass() {}

void ComodoMainClass::tunrOnOffLight(String sComodo, String sCircuito, int iState) {
  auto comodo = classFactory->GetClass(sComodo.c_str());
  auto circuito = operatorFactory->GetOperator(sCircuito.c_str());
  circuito(comodo, iState);
}

ComodoClass* ComodoMainClass::getComodo(String sComodo) {
  return classFactory->GetClass(sComodo.c_str());
}

void ComodoMainClass::onOffCentral(ComodoClass* comodo, int iState) {
  comodo->turnOnOffCentral(iState);
}

void ComodoMainClass::onOffCorredor(ComodoClass* comodo, int iState) {
  comodo->turnOnOffCorredor(iState);
}

void ComodoMainClass::onOffCroicas(ComodoClass* comodo, int iState) {
  comodo->turnOnOffCroicas(iState);
}

void ComodoMainClass::onOffLed(ComodoClass* comodo, int iState) {
  comodo->turnOnOffLed(iState);
} 

void ComodoMainClass::onOffBox(ComodoClass* comodo, int iState) {
  comodo->turnOnOffBox(iState);
}

void ComodoMainClass::onOffAmericana(ComodoClass* comodo, int iState) {
  comodo->turnOnOffAmericana(iState);
}

void ComodoMainClass::onOffAreaServico(ComodoClass* comodo, int iState) {
  comodo->turnOnOffAreaServico(iState);
}

void ComodoMainClass::carregarCircuitos() {
  operatorFactory = OperatorFactory<ComodoClass*>::getInstance();
  
  auto central = std::bind(&ComodoMainClass::onOffCentral, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(CENTRAL.c_str(), central);

  auto corredor = std::bind(&ComodoMainClass::onOffCorredor, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(CORREDOR.c_str(), corredor);

  auto croicas = std::bind(&ComodoMainClass::onOffCroicas, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(CROICAS.c_str(), croicas);

  auto led = std::bind(&ComodoMainClass::onOffLed, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(LED.c_str(), led);
  
  auto box = std::bind(&ComodoMainClass::onOffBox, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(BOX.c_str(), box);

  auto areaServico = std::bind(&ComodoMainClass::onOffAreaServico, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(AREA_SERVICO.c_str(), areaServico);

  auto americana = std::bind(&ComodoMainClass::onOffAmericana, this, std::placeholders::_1, std::placeholders::_2);
  operatorFactory->AddOperator(AMERICANA.c_str(), americana);

}

void ComodoMainClass::carregarComodos() {
  classFactory = ClassFactory<ComodoClass*>::getInstance();
  classFactory->AddClass("SALA", SalaClass::getInstance());
  classFactory->AddClass("COZINHA", CozinhaClass::getInstance());
  classFactory->AddClass("QUARTO_VISITA", QuartoVisitaClass::getInstance());
  classFactory->AddClass("QUARTO_CASAL", QuartoCasalClass::getInstance());
  classFactory->AddClass("BANHEIRO", BanheiroClass::getInstance());
}
