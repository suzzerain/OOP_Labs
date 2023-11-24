#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>
#include <QString>
#include <vector>
#include "squarematrix.h"

using namespace std;


template <class number>
class TMatrix {
public:
    TMatrix();
    TMatrix(int, int);
    void setNumbers(vector<vector<number>>&);
    void setSize(int, int);
    int getRows() const;
    int getCols() const;

    template <typename T>
    friend QString& operator<< (QString&, TMatrix<T>&);
    void transpose();
    int calculateRank();

protected:
    vector<vector<number>> numbers;
    int rows, cols;
    void Gauss();
};



template <class number>
TMatrix<number>::TMatrix() {
    rows = 3;
    cols = 3;
    numbers.resize(rows, vector<number>(cols, 0));
}


template <class number>
TMatrix<number>::TMatrix(int xRows, int yCols) {
    rows = xRows;
    cols = yCols;
    numbers.resize(rows, vector<number>(cols, 0));
}


template <class number>
void TMatrix<number>::setNumbers(vector<vector<number>>& newNumbers) {
    if(newNumbers.size() != rows && newNumbers[0].size() != cols){
        cout << "Wrong size\n";
        return;
    }

    numbers = newNumbers;
}


template <class number>
void TMatrix<number>::setSize(int newRows, int newCols) {
    if(newRows <= 0 || newCols <= 0) {
        cout << "Wrong size\n";
        return;
    }

    if(newRows == rows && newCols == cols){
        return;
    }
    else if(newRows < rows && newCols < cols){
        numbers.resize(newRows, vector<number>(newCols));
        rows = newRows;
        cols = newCols;
    }
    else{
        vector<vector<number>> newNumbers(newRows, vector<number>(newCols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                newNumbers[i][j] = numbers[i][j];
            }
        }
        numbers = newNumbers;
        rows = newRows;
        cols = newCols;
    }
}


template <class number>
int TMatrix<number>::getRows() const {
    return rows;
}


template <class number>
int TMatrix<number>::getCols() const {
    return cols;
}


template <class number>
QString& operator<< (QString& s, TMatrix<number>& matrix) {
    int xSize = matrix.getRows();
    int ySize = matrix.getCols();
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            s << matrix.numbers[i][j];
            s += "\t";
        }
        s += "\n";
    }
    return s;
}


template <class number>
void TMatrix<number>::Gauss(){
    int rowsUp = 0;
    for(int pC = 0; pC < rows; pC++){
        int pR = -1;
        for(int i = pC; i < cols; i++){
            if(numbers[i][pC] != 0){
                pR = i;
                break;
            }
        }
        if(pR == -1) continue;

        if(pR != rowsUp){
            swap(numbers[rowsUp], numbers[pR]);
            pR = rowsUp;
        }
        for(int i = pR + 1; i < rows; i++){
            number fc = numbers[i][pC] / numbers[pR][pC];
            for(int j = pC; j < cols; j++){
                numbers[i][j] = numbers[i][j] - numbers[pR][j] * fc;
            }
        }
        rowsUp++;
        if(rowsUp == cols - 1) break;
    }
}



template <class number>
int TMatrix<number>::calculateRank() {
    TMatrix matrix(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix.numbers[i][j] = numbers[i][j];
        }
    }
    matrix.Gauss();

    int rank = 0;
    for(int i = 0; i < rows; i++){
        for(int j = i; j < cols; j++){
            if(matrix.numbers[i][j] != 0){
                rank++;
                break;
            }
        }
    }
    return rank;
}


template <class number>
void TMatrix<number>::transpose() {
    for(int i = 0; i < rows; i++){
        for(int j = i + 1; j < cols; j++){
            swap(numbers[i][j], numbers[j][i]);
        }
    }
}
#endif  // TMATRIX_H
