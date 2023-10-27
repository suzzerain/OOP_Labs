#include "matrix.h"



TMatrix::TMatrix() {
    data[0][0] = number(0, 1);
    data[0][1] = number(0, 1);
    data[1][0] = number(0, 1);
    data[1][1] = number(0, 1);
}



void TMatrix::inputMatrix(number a, number b, number c, number d) {
    data[0][0] = a;
    data[0][1] = b;
    data[1][0] = c;
    data[1][1] = d;
}



number TMatrix::calculateDet() {
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
}



int TMatrix::calculateRank() {
    return 2;
}
