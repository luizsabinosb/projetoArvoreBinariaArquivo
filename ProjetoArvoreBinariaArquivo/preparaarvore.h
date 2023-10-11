#ifndef PREPARAARVORE_H
#define PREPARAARVORE_H
#include <iostream>
#include <vector>
#include <QString>

namespace km{
class PreparaArvore
{
public:
    PreparaArvore();
    std::vector<int> SepararVertices(QString texto);
};
}
#endif // PREPARAARVORE_H
