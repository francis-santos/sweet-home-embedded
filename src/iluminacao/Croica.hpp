#ifndef CROICA_H
#define CROICA_H

#include <iostream>
#include "Iluminacao.hpp"

using namespace std;

class Croica : public Iluminacao {
  private:
    static Croica* instancia;
    Croica(Comodo* comodo, int porta);
  public:
    static Croica* getInstancia(Comodo* comodo, int porta);
    virtual void ligarIluminacao();
    virtual void desligarIluminacao();
    virtual void setarPorta(int porta);
    virtual ~Croica();
};

#endif
