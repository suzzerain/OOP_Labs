#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "communicator.h"

class TApplication : public QCoreApplication {
    Q_OBJECT

    communicator *comm;

public:
    TApplication(int, char**);

signals:


public slots:
    void recieve(QByteArray);
};

#endif // TAPPLICATION_H
