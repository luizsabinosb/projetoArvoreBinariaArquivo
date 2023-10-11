#include "ArvoreBinaria.h"

namespace km{
ArvoreBinaria::ArvoreBinaria():
    raiz(0)
{
}

ArvoreBinaria::~ArvoreBinaria()
{
    if(raiz != 0){
        delete raiz;
    }
}

void ArvoreBinaria::imprimir(std::vector<int> &v, int i)
{
    if(i == 1){
        return PreFixadoEsquerda(raiz, v);
    }
    if(i == 2){
        return CentralAEsquerda(raiz,v);
    }
    if(i == 3){
        return PosFixadoAEsquerda(raiz,v);
    }
    if(i == 4){
        return PreFixadoDireita(raiz,v);
    }
    if(i == 5){
        return CentralADireita(raiz,v);
    }
    return PosFixadoADireita(raiz,v);
}

void ArvoreBinaria::inserirRecursivo(No **raiz, int elemento){
    if(*raiz == 0){
        *raiz = new No(elemento);
    }else
        if(elemento < (*raiz)->getDado())
            inserirRecursivo(&(*raiz)->esquerda, elemento);
        else
            if(elemento > (*raiz)->getDado() )
                inserirRecursivo(&(*raiz)->direita, elemento);
            else throw std::string("Elemento já Existe");
}

void ArvoreBinaria::CentralADireita(No* raiz, std::vector<int> &v){
    if(raiz != 0){
        CentralADireita(raiz->getDireita(), v);
        v.push_back(raiz->getDado());
        CentralADireita(raiz->getEsquerda(), v);

    }
}

void ArvoreBinaria::CentralAEsquerda(No *raiz, std::vector<int> &v)
{   if(raiz != 0){
        CentralAEsquerda(raiz->getEsquerda(), v);
        v.push_back(raiz->getDado());
        CentralAEsquerda(raiz->getDireita(), v);
   }
}

void ArvoreBinaria::PreFixadoEsquerda(No *raiz, std::vector<int> &v)
{
    if(raiz != 0){
        v.push_back(raiz->getDado());
        PreFixadoEsquerda(raiz->getEsquerda(), v);
        PreFixadoEsquerda(raiz->getDireita(), v);
    }
}

void ArvoreBinaria::PosFixadoAEsquerda(No *raiz, std::vector<int> &v)
{
    if(raiz != 0){
        PosFixadoAEsquerda(raiz->getEsquerda(), v);
        PosFixadoAEsquerda(raiz->getDireita(), v);
        v.push_back(raiz->getDado());
    }
}

void ArvoreBinaria::PreFixadoDireita(No *raiz, std::vector<int> &v)
{
    if(raiz != 0){
        v.push_back(raiz->getDado());
        PreFixadoDireita(raiz->getDireita(), v);
        PreFixadoDireita(raiz->getEsquerda(), v);
    }
}

void ArvoreBinaria::PosFixadoADireita(No *raiz, std::vector<int> &v)
{
    if(raiz != 0){
        PosFixadoADireita(raiz->getDireita(), v);
        PosFixadoADireita(raiz->getEsquerda(), v);
        v.push_back(raiz->getDado());

    }
}

int ArvoreBinaria::retornar_Maior(No **raiz){
    int valor;
    No *aux = 0;
    if((*raiz)->direita != 0) return (retornar_Maior(&(*raiz)->direita));
    else{
        aux = *raiz;
        valor = (*raiz)->getDado();
        *raiz = (*raiz)->esquerda;
        aux->esquerda = 0;
        aux->direita = 0;
        delete aux;
        return valor;
    }
}

void ArvoreBinaria::removerRecursivo(No **raiz, int elemento){
    No *aux = 0;
    //std::cout<<std::endl<<"Remover Recursivo1"<<std::endl;
    if(*raiz != 0){
        //std::cout<<std::endl<<"Remover Recursivo2"<<std::endl;
        //std::cout<<"dado = "<<(*raiz)->getDado();
        if((*raiz)->getDado() == elemento){
            //std::cout<<std::endl<<"Remover Recursivo3"<<std::endl;
            aux = *raiz;
            if((*raiz)->esquerda == 0){
                *raiz = (*raiz)->direita;
                aux->esquerda = 0;
                aux->direita = 0;
                delete aux;
            }else
                if((*raiz)->direita == 0){
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = 0;
                    aux->direita = 0;
                    delete aux;
                }else
                    {
                        (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                    }
        }else
            {
                if((*raiz)->getDado() < elemento)
                    removerRecursivo(&(*raiz)->direita,elemento);
                else
                    if((*raiz)->getDado() > elemento)
                        removerRecursivo(&(*raiz)->esquerda,elemento);
        }

    }//ok
    else throw std::string("Elemento não Existe");//ok
}

}
