#include "No.h"

namespace km{
No::No(int dado):
    dado(dado),
    esquerda(0),
    direita(0)
{
}

No::~No()
{
    if(this->esquerda != 0) delete this->esquerda;
    if(this->direita != 0)  delete this->direita;
}

}
