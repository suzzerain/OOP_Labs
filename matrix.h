#ifndef TMATRIX_H
#define TMATRIX_H

#include "complex.h"
#include <iostream>

using namespace std;



class TMatrix {

private:
    TComplex* *data;
    int size;

public:
    TMatrix();
    void inputMatrix();
    TComplex calculateDet();
    void transposedMatrix();
    int calculateRank();

    friend ostream& operator << (ostream& os, const TMatrix& matrix);

};

#endif // TMATRIX_H
