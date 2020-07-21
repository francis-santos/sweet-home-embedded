#include "Iluminacao.hpp"

Iluminacao::Iluminacao(Comodo * comodo, int porta) {
  comodo = comodo;
};

void Iluminacao::ligarIluminacao() {
  comodo->ligarIluminacao();
};

void Iluminacao::desligarIluminacao() {
  comodo->desligarIluminacao();
};

void Iluminacao::setarPorta(int porta) {};

Iluminacao::~Iluminacao() {};