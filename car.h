#ifndef CAR_H
#define CAR_H

#include <track.h>
#include <math.h>

#include <QVector2D>
#include <QPainter>
#include <QMatrix>

class Car {
    QVector2D pos;
    int rotate;
    int width;

public:
    Car();
    Car(int x, int y, int width, int rotate);

    void draw(QPainter* p);
    void moveF(int speed, float timer);
    void setPos(QVector2D pos);
    bool dotTrack(Track& r);

    QVector2D getPos();
    void rotateOn(float angle);
    void setRotate(float angle);
};

#endif // CAR_H
