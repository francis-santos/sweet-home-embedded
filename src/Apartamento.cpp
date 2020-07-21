#include "Apartamento.hpp"

Apartamento::Apartamento() {}

void Apartamento::setComodo(Comodo * comodo) {
  cout << "Ap: setComodo" << endl;
  comodo = comodo;
}

Comodo* Apartamento::getComodo() {
  cout << "Ap: getComodo" << endl;
  return comodo;
}
