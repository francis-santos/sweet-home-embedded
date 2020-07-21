#ifndef SALA_H
#define SALA_H

#include <iostream>
#include "Comodo.hpp"

using namespace std;

class Sala : public Comodo {
public:
    Sala();
    virtual void ligarIluminacao();
    virtual void desligarIluminacao();
    virtual void setarPorta(int porta);
    virtual ~Sala();
};

#endif
