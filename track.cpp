#include "track.h"



Track::Track() {
    float scale = 0.75;
    center = QVector2D(400, 300);
    length = 200 * scale;
    r1 = 300 * scale;
    r2 = 155 * scale;
}


Track::Track(int x, int y, int l, int rad1, int rad2) {
    float scale = 0.75;
    center = QVector2D(x, y);
    length = l * scale;
    r1 = rad1 * scale;
    r2 = rad2 * scale;
}



int Track::getWidth() {
    return r1 - r2;
}



int Track::getR2() {
    return r2;
}



int Track::getR1() {
    return r1;
}



int Track::getLength() {
    return length;
}



QVector2D Track::getCenter() {
    return center;
}



void Track::draw(QPainter* p) {
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);

    p->setPen(pen);
    p->drawLine(center.x() - length / 2, center.y() - r2, center.x() + length / 2, center.y() - r2);
    p->drawLine(center.x() - length / 2, center.y() + r2, center.x() + length / 2, center.y() + r2);
    p->drawLine(center.x() - length / 2, center.y() - r1, center.x() + length / 2, center.y() - r1);
    p->drawLine(center.x() - length / 2, center.y() + r1, center.x() + length / 2, center.y() + r1);

    int startAngle = -90 * 16;
    int spanAngle = 180 * 16;

    p->drawArc(center.x() + length / 2 - r2, center.y() - r2, r2 * 2, r2 * 2, startAngle, spanAngle);
    startAngle = 90 * 16;
    spanAngle = 180 * 16;

    p->drawArc(center.x() - length / 2 - r2, center.y() - r2, r2 * 2, r2 * 2, startAngle, spanAngle);
    startAngle = -90 * 16;
    spanAngle = 180 * 16;

    p->drawArc(center.x() + length / 2 - r1, center.y() - r1, r1 * 2, r1 * 2, startAngle, spanAngle);
    startAngle = 90 * 16;
    spanAngle = 180 * 16;

    p->drawArc(center.x() - length / 2 - r1, center.y() - r1, r1 * 2, r1 * 2, startAngle, spanAngle);
}
