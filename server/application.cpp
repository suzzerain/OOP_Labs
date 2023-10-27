#include "application.h"
#include "common.h"
#include "matrix.h"


TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm, SIGNAL(recieved(QByteArray)), this, SLOT(recieve(QByteArray)));
}



void TApplication::recieve(QByteArray msg) {
    QString answer, s;

    number a, b, c, d;
    msg >> a >> b >> c >> d;

    int t = (msg.mid(msg.length() - 2, 1).toInt());
    if(!a.getDenominator() || !b.getDenominator() || !c.getDenominator() || !d.getDenominator()){
        answer << QString::number(ERROR);
        comm->send(QByteArray().append(answer));
    }
    else{
        switch(t) {
           case MATRIX_REQUEST: {
              TMatrix matrix;
              matrix.inputMatrix(a, b, c, d);
              answer << QString::number(MATRIX_ANSWER);
              answer << a;
              answer << b;
              answer << c;
              answer << d;
              break;
           }

           case TRANSPOSE_REQUEST: {
              TMatrix matrix;
              answer << QString::number(TRANSPOSE_ANSWER);
              answer << a;
              answer << c;
              answer << b;
              answer << d;
              break;
           }

           case DETERMINANT_REQUEST: {
              TMatrix matrix;
              matrix.inputMatrix(a, b, c, d);
              number det = matrix.calculateDet();
              answer << QString::number(DETERMINANT_ANSWER);
              answer << det;
              break;
           }

           case RANK_REQUEST: {
              TMatrix matrix;
              int rank = matrix.calculateRank();
              answer << QString::number(RANK_ANSWER) << QString::number(rank);
              break;
           }

           default:
              return;
       }
       comm->send(QByteArray().append(answer));
    }
}
