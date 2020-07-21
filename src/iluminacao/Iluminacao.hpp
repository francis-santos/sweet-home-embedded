#ifndef ILUMINACAO_H
#define ILUMINACAO_H

#include "../comodo/Comodo.hpp"

class Iluminacao : public Comodo {
  private:
    Comodo * comodo;
  public:
    Iluminacao(Comodo * comodo, int porta);
    virtual void ligarIluminacao() = 0;
    virtual void desligarIluminacao() = 0;
    virtual void setarPorta(int porta) = 0;
    virtual ~Iluminacao();
};

#endif // ILUMINACAO_H
