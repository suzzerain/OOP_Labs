#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"
#include <vector>

template <class number>
class squareMatrix : public TMatrix<number> {
public:
    squareMatrix(int size) : TMatrix<number>(size, size) {}

    int getSize() const;

    number calculateDet();
};


template <class number>
int squareMatrix<number>::getSize() const {
    return TMatrix<number>::getRows();
}


template <class number>
number squareMatrix<number>::calculateDet() {
    squareMatrix matrix(this->rows);

    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->rows; j++){
            matrix.numbers[i][j] = this->numbers[i][j];
        }
    }
    matrix.Gauss();

    number determinant(1);
    for(int i = 0; i < this->rows; i++){
        determinant = determinant * matrix.numbers[i][i];
    }
    return determinant;
}

#endif // SQUAREMATRIX_H
