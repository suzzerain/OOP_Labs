#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

struct TCommParams {
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};



class communicator : public QUdpSocket {
    Q_OBJECT

    bool         ready;
    TCommParams  params;

public:
    communicator(TCommParams&,QObject *parent = nullptr);
    bool isReady();

signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void recieve();
};

#endif // COMMUNICATOR_H
