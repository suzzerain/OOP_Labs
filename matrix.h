#ifndef TMATRIX_H
#define TMATRIX_H

#include "number.h"
#include <iostream>

using namespace std;



class TMatrix {

private:
    number* *data;
    int size;

public:
    TMatrix();
    void inputMatrix();
    number calculateDet();
    void transposedMatrix();
    int calculateRank();

    friend ostream& operator << (ostream& os, const TMatrix& matrix);

};

#endif // TMATRIX_H

