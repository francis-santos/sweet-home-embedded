#include "Sala.hpp"

Sala::Sala() {};

void Sala::ligarIluminacao() {
  cout << "Sala: Luz ligada!" << endl;
};

void Sala::desligarIluminacao() {
  cout << "Sala: Luz desligada!" << endl;
};

void Sala::setarPorta(int porta) {
  cout << "Sala: porta " << porta << " setada!" << endl;
};

Sala::~Sala() {};
