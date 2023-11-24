#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include <vector>

#include "communicator.h"
#include "common.h"
#include "squarematrix.h"
#include "rational.h"
#include "complex.h"
#include "double.h"

class TApplication : public QCoreApplication {
    Q_OBJECT

    TCommunicator *comm;

    template <class number>
    void send(QByteArray&, squareMatrix<number>&);

public:
    TApplication(int, char**);

public slots:
    void recieve(QByteArray);
};



template <class number>
void TApplication::send(QByteArray& msg, squareMatrix<number>& matrix){
    QString answer, s;

    int p = (int) msg.indexOf(separator);
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
             s += QString::number(matrix.calculateRank());
             answer << QString().setNum(RANK_ANSWER) << s;
             break;
        }
        case ERROR: {
             answer << QString().setNum(ERROR) << s;
        }
        default: {
             return;
        }
   }
   comm->send(QByteArray().append(answer));
}
#endif // TAPPLICATION_H
