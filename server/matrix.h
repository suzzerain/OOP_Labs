#ifndef TMATRIX_H
#define TMATRIX_H

#include "number.h"
#include <iostream>
#include <QString>
#include <vector>

using namespace std;

class TMatrix {
public:
    TMatrix();
    TMatrix(int, int);
    void setNumbers(vector<vector<number>>&);
    void setSize(int, int);
    int getRows() const;
    int getCols() const;

    friend QString& operator<< (QString&, TMatrix&);
    void transpose();
    int calculateRank();

protected:
    vector<vector<number>> numbers;
    int rows, cols;
};

#endif  // TMATRIX_H
