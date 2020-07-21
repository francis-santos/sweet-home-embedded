#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
#include "comodo/Comodo.hpp"

using namespace std;

class Apartamento {
  private:
    Comodo * comodo;
  public:
    Apartamento();
    void setComodo(Comodo * comodo);
    Comodo* getComodo();
    ~Apartamento() {};
};

#endif
