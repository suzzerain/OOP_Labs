#include "application.h"
#include "common.h"
#include "matrix.h"
#include "squarematrix.h"



TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm, SIGNAL(recieved(QByteArray)), this, SLOT(recieve(QByteArray)));
}



QByteArray& operator>> (QByteArray& arr, int& r) {
    int p = arr.indexOf(separator);
    if(p > 0){
        r = arr.left(p).toInt();
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}



void TApplication::recieve(QByteArray msg) {
    QString answer, s;

    int sizeMatrix;
    msg >> sizeMatrix;
    vector<vector<number>> numbers(sizeMatrix, vector<number>(sizeMatrix, 0));
    for(int i = 0; i < sizeMatrix; i++){
        for(int j = 0; j < sizeMatrix; j++){
            number num;
            msg >> num;
            if(num.denominator == 0){
                answer << QString::number(ERROR);
                comm->send(QByteArray().append(answer));
                return;
            }
            numbers[i][j] = num;
        }
    }
    squareMatrix matrix(sizeMatrix);
    matrix.setNumbers(numbers);

    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();

    switch(t) {
        case MATRIX_REQUEST: {
           s << matrix;
           answer << QString().setNum(MATRIX_ANSWER) << s;
           break;
        }

        case TRANSPOSE_REQUEST: {
           matrix.transpose();
           s << matrix;
           answer << QString().setNum(TRANSPOSE_ANSWER) << s;
           break;
        }

        case DETERMINANT_REQUEST: {
           s << matrix.calculateDet();
           answer << QString().setNum(DETERMINANT_ANSWER) << s;
           break;
        }

        case RANK_REQUEST: {
           s << QString::number(matrix.calculateRank());
           answer << QString().setNum(RANK_ANSWER) << s;
           break;
        }

        default: {
          return;
       }
    }
    comm->send(QByteArray().append(answer));
}
