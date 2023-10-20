#include "application.h"
#include "common.h"
#include "matrix.h"
#include "number.h"


TApplication::TApplication(int argc, char *argv[]) : QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new communicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}



void TApplication::recieve(QByteArray msg) {

    QString answer, s;
    number a, b, c,  d;
    msg >> a >> b >> c >> d;
    TMatrix matrix;
    matrix.inputMatrix(a, b, c, d);

    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();

    switch (t) {
        case MATRIX_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            //msg >> a >> b >> c >> d;
            //matrix.inputMatrix(a, b, c, d);
            s << (QString)a.getNumerator() << (QString)a.getDenominator() << (QString)b.getNumerator() << (QString)b.getDenominator()
                  << (QString)c.getNumerator() << (QString)c.getDenominator() << (QString)d.getNumerator() << (QString)d.getDenominator();
            answer << QString().setNum(MATRIX_ANSWER);
            answer += s;
            break;
        case PRINT_MATRIX_REQUEST:
            //m.setPrintMode(EPRINTMATRIXCLASSIC);
            //s << p;

            answer << QString().setNum(PRINT_ANSWER) << s;
            break;
        default:
            return;
    }
    comm->send(QByteArray().append(answer));
}
