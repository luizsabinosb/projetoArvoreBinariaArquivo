#include "preparaarvore.h"
namespace km{
PreparaArvore::PreparaArvore()
{

}

std::vector<int> PreparaArvore::SepararVertices(QString texto)
{
    QString aux= "";
    std::vector<int> v;
    for(int i = 0; i<texto.size(); i++){
        if(texto[i] != '\n' and texto[i]!= ' '){
            aux+= texto[i];
        }else{
            v.push_back(aux.toInt());
            aux= "";
        }
    }
    v.push_back(aux.toInt());
    aux= "";
    return v;
}
}
