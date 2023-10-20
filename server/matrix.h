#ifndef TMATRIX_H
#define TMATRIX_H


#include "number.h"
#include <iostream>

class TMatrix {
private:
    number data[2][2];

public:
    TMatrix();
    void inputMatrix(number a, number b, number c, number d);
    number calculateDet();
    int calculateRank();

    //friend std::ostream& operator<< (std::ostream&, TMatrix&);

    friend QString& operator<< (QString&, TMatrix&);
};

#endif // TMATRIX_H
