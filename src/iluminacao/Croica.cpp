#include "Croica.hpp"

Croica* Croica::instancia = 0;

Croica::Croica(Comodo * comodo, int porta) : Iluminacao(comodo, porta) {};

Croica* Croica::getInstancia(Comodo* comodo, int porta) {
  if (instancia == 0) {
    instancia = new Croica(comodo, porta);
  }
  return instancia;
}

void Croica::ligarIluminacao() {
  this->ligarIluminacao();
};

void Croica::desligarIluminacao() {
  this->desligarIluminacao();
};

void Croica::setarPorta(int porta) {
  cout << "Croica: porta " << porta << " setada!" << endl;
};

Croica::~Croica() {};
