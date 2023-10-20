#include "matrix.h"
#include "complex.h"
#include "number.h"


TMatrix::TMatrix() {

    data = nullptr;
    size = 0;
}



void TMatrix::inputMatrix() {

    cout << "Enter the matrix dimension: ";
    cin >> size;

    data = new number*[size];
    for(int i = 0; i < size; i++){
        data[i] = new number[size];
    }

    cout << "Enter elements matrix: " << size << "x" << size << ":\n";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> data[i][j];
        }
    }
}



TComplex TMatrix::calculateDet() {

    if(size == 1){
        return data[0][0];
    }
    else if(size == 2){
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    else{
        number det(0,0);
        for(int j = 0; j < size; j++){
            TMatrix minor;
            minor.size = size - 1;
            minor.data = new number*[minor.size];

            for(int i = 0; i < minor.size; i++){
                minor.data[i] = new number[minor.size];
            }

            for(int row = 1; row < size; row++){
                int colIdx = 0;
                for(int col = 0; col < size; col++){
                    if(col == j) continue;
                    minor.data[row-1][colIdx++] = data[row][col];
                }
            }

            number minorDet = minor.calculateDet();
            det = det + (j % 2 == 0 ? number(1,0) : number(-1,0)) * data[0][j] * minorDet;
            for(int i = 0; i < minor.size; i++){
                delete[] minor.data[i];
            }

            delete[] minor.data;
        }

        return det;
    }
}



int TMatrix::calculateRank() {

    int rank = 0;

    TMatrix copy = *this;

    for(int i = 0; i < size; i++){
        TMatrix minor;
        minor.size = size - 1;
        minor.data = new number*[minor.size];

        for(int j = 0; j < minor.size; j++){
            minor.data[j] = new number[minor.size];
        }

        for(int row = 1; row < size; row++){
            int minorRow = row - 1;

            for(int col = 0; col < size; col++){
                if(col != i){
                    minor.data[minorRow][col < i ? col : col - 1] = copy.data[row][col];
                }
            }
        }

        number minorDet = minor.calculateDet();

        if(minorDet != number(0,0)){
            rank++;
        }

        for(int j = 0; j < minor.size; j++){
            delete[] minor.data[j];
        }
        delete[] minor.data;
    }

    return rank;
}



void TMatrix::transposedMatrix() {

    number* *transpose = new number*[size];

    for(int i = 0; i < size; i++){
        transpose[i] = new number[size];
        for(int j = 0; j < size; j++){
            transpose[i][j] = data[j][i];
        }
    }

    for(int i = 0; i < size; i++){
        delete[] data[i];
    }

    delete[] data;

    data = transpose;
}



ostream& operator << (ostream& os, const TMatrix& matrix) {

    os << "Matrix " << matrix.size << "x" << matrix.size << ":\n";
    for(int i = 0; i < matrix.size; i++){
        for(int j = 0; j < matrix.size; j++){
            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
