#include "application.h"
#include "common.h"
#include "rational.h"
#include "complex.h"
#include "double.h"
#include "matrix.h"
#include "squarematrix.h"



TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm, SIGNAL(recieved(QByteArray)), this, SLOT(recieve(QByteArray)));
}



QByteArray& operator>> (QByteArray& arr, int& r) {
    int p = (int) arr.indexOf(separator);
    if(p > 0){
        r = arr.left(p).toInt();
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}



void TApplication::recieve(QByteArray msg) {
    int sizeMatrix, Number;
    msg >> sizeMatrix;
    msg >> Number;

    if(Number == DOUBLE_MODE){
       std::vector<std::vector<double>> numbers(sizeMatrix, std::vector<double>(sizeMatrix, 0));
       for(int i = 0; i < sizeMatrix; i++){
           for(int j = 0; j < sizeMatrix; j++){
               double num;
               msg >> num;
               numbers[i][j] = num;
           }
        }
        squareMatrix<double> matrix(sizeMatrix);
        matrix.setNumbers(numbers);
        send(msg, matrix);
    }
    else if(Number == COMPLEX_MODE){
        vector<vector<Complex>> numbers(sizeMatrix, vector<Complex>(sizeMatrix, 0));
        for(int i = 0; i < sizeMatrix; i++){
            for(int j = 0; j < sizeMatrix; j++){
                Complex num;
                msg >> num;
                numbers[i][j] = num;
            }
         }
         squareMatrix<Complex> matrix(sizeMatrix);
         matrix.setNumbers(numbers);
         send(msg, matrix);
    }
    else{
        bool flag = false;
        vector<vector<TRational>> numbers(sizeMatrix, vector<TRational>(sizeMatrix, 0));
        for(int i = 0; i < sizeMatrix; i++){
            for(int j = 0; j < sizeMatrix; j++){
                TRational num;
                if(num.denominator == 0){
                    flag = true;
                }
                msg >> num;
                numbers[i][j] = num;
            }
         }
         squareMatrix<TRational> matrix(sizeMatrix);
         matrix.setNumbers(numbers);
         send(msg, matrix);
    }
}
