#ifndef TMATRIX_H
#define TMATRIX_H

#include "number.h"
#include <iostream>

using namespace std;

class TMatrix {
private:
    number data[2][2];

public:
    TMatrix();
    void inputMatrix(number a, number b, number c, number d);
    number calculateDet();
    int calculateRank();
};

#endif // TMATRIX_H
