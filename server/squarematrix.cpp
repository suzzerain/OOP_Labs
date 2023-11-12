#include "squarematrix.h"



int squareMatrix::getSize() const {
    return rows;
}



number squareMatrix::calculateDet() {
    if(rows == 1){
        return numbers[0][0];
    }
    else if(rows == 2){
        return numbers[0][0] * numbers[1][1] - numbers[0][1] * numbers[1][0];
    }
    else{
        number det = 0;
        for(int j = 0; j < rows; j++){
            squareMatrix minor(rows - 1);
            minor.rows = rows - 1;
            minor.setSize(rows-1);

            for(int row = 1; row < rows; row++){
                int colIdx = 0;
                for(int col = 0; col < rows; col++){
                    if(col == j) continue;
                    minor.numbers[row-1][colIdx++] = numbers[row][col];
                }
            }
            number minorDet = minor.calculateDet();
            det = det + ((j % 2 == 0 ? number(1,1) : number(-1,1)) * numbers[0][j] * minorDet);
        }

        return det;
    }
}



squareMatrix::squareMatrix(int size) {
    rows = size;
    cols = size;
    numbers.resize(rows, vector<number>(cols, 0));
}



void squareMatrix::setSize(int newSize) {
    if(newSize <= 0){
       cout << "Wrong size\n";
       return;
    }
    if(newSize == rows){
       return;
    }
    else if(newSize < rows){
       numbers.resize(newSize, vector<number>(newSize));
       rows = newSize;
       cols = newSize;
    }
    else {
       vector<vector<number>> newNumbers(newSize, vector<number>(newSize, 0));
       for(int i = 0; i < rows; ++i){
           for(int j = 0; j < rows; ++j){
                newNumbers[i][j] = numbers[i][j];
           }
       }
       numbers = newNumbers;
       rows = newSize;
       cols = newSize;
    }
}
