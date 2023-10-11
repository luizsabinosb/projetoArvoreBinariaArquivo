#ifndef IARVOREBINARIA_H
#define IARVOREBINARIA_H
#include <QString>
namespace km{
class IArvoreBinaria{
    virtual void inserir(int elemento) = 0;
    virtual void imprimir(std::vector<int> &v, int i) = 0;
    virtual void remover(int elemento) = 0;
};
}
#endif // IARVOREBINARIA_H
