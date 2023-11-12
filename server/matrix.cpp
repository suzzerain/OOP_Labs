#include "matrix.h"
#include "squarematrix.h"


TMatrix::TMatrix() {
    rows = 3;
    cols = 3;
    numbers.resize(rows, vector<number>(cols, 0));
}



TMatrix::TMatrix(int xRows, int yCols) {
    rows = xRows;
    cols = yCols;
    numbers.resize(rows, vector<number>(cols, 0));
}



void TMatrix::setNumbers(vector<vector<number>>& newNumbers) {
    if(newNumbers.size() != rows && newNumbers[0].size() != cols){
        cout << "Wrong size\n";
        return;
    }

    numbers = newNumbers;
}



void TMatrix::setSize(int newRows, int newCols) {
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




int TMatrix::getRows() const {
    return rows;
}



int TMatrix::getCols() const {
    return cols;
}




QString& operator<< (QString& s, TMatrix& matrix) {
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



int TMatrix::calculateRank() {
    int rank = 1;
    for(int minorSize = 2; minorSize <= rows; minorSize++){
        squareMatrix minor(minorSize);
        minor.cols = minorSize;
        minor.rows = minorSize;
        minor.setSize(minorSize);

        for(int i = 0; i < minorSize; i++){
            for(int j = 0; j< minorSize;j++){
                minor.numbers[i][j] = numbers[i][j];
            }
        }
        if(minor.calculateDet().numerator != 0){
           rank++;
        }
        else{
           return rank;
        }
    }
    return rank;
}



void TMatrix::transpose() {
    for(int i = 0; i < rows; i++){
        for(int j = i + 1; j < cols; j++){
            swap(numbers[i][j], numbers[j][i]);
        }
    }
}
