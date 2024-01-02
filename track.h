#ifndef TRACK_H
#define TRACK_H

#include <QVector2D>
#include <QPainter>
#include <QRectF>

class Track {
    QVector2D center;
    int length;
    int r1, r2;

public:
    Track();
    Track(int x, int y, int l, int rad1, int rad2);

    int getWidth();
    int getR2();
    int getR1();
    int getLength();

    QVector2D getCenter();
    void draw(QPainter* p);
};

#endif // TRACK_H
