#ifndef PAINTER_H
#define PAINTER_H

#include "car.h"
#include "track.h"

#include <QWidget>
#include <QTimer>

class Painter : public QWidget {
    Q_OBJECT
    QTimer* timer;
    int speed;

protected:
    void paintEvent(QPaintEvent* event);

public:
    Painter(QWidget* parent = nullptr);

    bool started;
    void setSpeed(int value);

    Track* r;
    Car* c;

public slots:
    void timeUpd();
};

#endif // PAINTER_H
