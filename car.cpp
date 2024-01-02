#include "car.h"


Car::Car() {
    pos = QVector2D(0, 0);
    rotate = 0;
    width = 60;
}



Car::Car(int x, int y, int width, int rotate) {
    pos = QVector2D(x, y);
    this->rotate = rotate;
    this->width = width;
}



void Car::draw(QPainter* p) {
    QImage image(":/resource/carpattern.png");

    int length = width * 1.5;
    QVector<QPoint> points;
    points.append(QPoint{(int) pos.x() - length / 2, (int) pos.y() - width / 2});
    points.append(QPoint{(int) pos.x() + length / 2, (int) pos.y() - width / 2});
    points.append(QPoint{(int) pos.x() + length / 2, (int) pos.y() + width / 2});
    points.append(QPoint{(int) pos.x() - length / 2, (int) pos.y() + width / 2});

    QMatrix rotationMatrix;
    rotationMatrix.rotate(rotate);

    for (int i = 0; i < 4; i++) {
        points[i] = QPoint(pos.x(), pos.y()) + (points[i] - QPoint(pos.x(), pos.y())) * rotationMatrix;
    }

    image = image.scaled(length, width);

    QTransform transform;
    transform.translate(points[0].x(), points[0].y());
    transform.rotate(rotate);
    p->setTransform(transform);

    p->drawImage(0, 0, image);

    p->resetTransform();

    for (int i = 0; i < 4; i++) {
        p->drawLine(points[i], points[(i + 1) % 4]);
    }
}



void Car::moveF(int speed, float timer) {
    int correctSpeed = (float) speed * timer;
    pos = QVector2D(pos.x() + correctSpeed * cos((double) rotate * 3.14159 / 180), pos.y() + correctSpeed * sin((double) rotate * 3.14159 / 180));
}



void Car::setPos(QVector2D pos) {
    this->pos = pos;
}



bool Car::dotTrack(Track& r) {
    QVector<QPoint> dots;

    QPoint dot(pos.x() + width * 3 * cos((double) rotate * 3.14159 / 180), pos.y() + width * 3 * sin((double) rotate * 3.14159 / 180));
    QPoint leftDot(pos.x() + width * cos((double) (rotate + 270) * 3.14159 / 180), pos.y() + width * sin((double) (rotate + 270) * 3.14159 / 180));
    dots.append(dot);
    dots.append(leftDot);

    for(int i = 0; i < dots.length(); i++){
        if(dots[i].x() > r.getCenter().x() + r.getLength() / 2){
            if(pow(dots[i].x() - (r.getCenter().x() + r.getLength() / 2), 2) + pow(dots[i].y() - r.getCenter().y(), 2) > pow(r.getR1(), 2))
                return 0;
        }
        else if(dots[i].x() > r.getCenter().x() - r.getLength() / 2){
            if(dots[i].y() < r.getCenter().y() - r.getR1() or dots[i].y() > r.getCenter().y() + r.getR1())
                return 0;
        }
        else{
            if (pow(dots[i].x() - (r.getCenter().x() - r.getLength() / 2), 2) + pow(dots[i].y() - r.getCenter().y(), 2) > pow(r.getR1(), 2))
                return 0;
        }
    }
    return 1;
}



QVector2D Car::getPos() {
    return pos;
}



void Car::setRotate(float angle) {
    rotate = angle;
    rotate = rotate % 360;
}



void Car::rotateOn(float angle) {
    rotate += angle;
    rotate = rotate % 360;
}
