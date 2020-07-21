#pragma once

#ifndef COMODO_H
#define COMODO_H

#include <iostream>

using namespace std;

class Comodo {
public:
  Comodo();
  virtual void ligarIluminacao() = 0;
  virtual void desligarIluminacao() = 0;
  virtual void setarPorta(int porta) = 0;
  virtual ~Comodo();
};

#endif
