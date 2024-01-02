#include "painter.h"



void Painter::paintEvent(QPaintEvent* event) {
    if(started){
        if(!c->dotTrack(*r))
            c->rotateOn(10);
        c->moveF(speed, 0.1);
    }
    QPainter p(this);
    r->draw(&p);
    c->draw(&p);
}



Painter::Painter(QWidget *parent) : QWidget(parent) {
    r = new Track(800 / 2, 500 / 2, 200, 300, 155);
    c = new Car(800 / 2, 500 / 2 - r->getR2() - r->getWidth() / 2, r->getWidth() / 3, 0);
    timer = new QTimer;

    connect(timer, &QTimer::timeout, this, &Painter::timeUpd);
    started = 0;
    timer->start(100);
}



void Painter::setSpeed(int value) {
    this->speed = value;
}



void Painter::timeUpd() {
    update();
}
