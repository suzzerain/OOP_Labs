#ifndef TAPPLICATION_H
#define TAPPLICATION_H


#include <QObject>
#include <QApplication>
#include "interface.h"
#include "communicator.h"



class TApplication : public QApplication {
    Q_OBJECT

    communicator *comm;
    TInterface *interface;

public:
    TApplication(int, char**);

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);
};

#endif // TAPPLICATION_H
