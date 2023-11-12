#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"
#include "number.h"
#include <vector>

class squareMatrix : public TMatrix {
public:
    squareMatrix(int);
    void setSize(int);
    int getSize() const;
    number calculateDet();
};

#endif // SQUAREMATRIX_H
