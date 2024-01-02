#include "interface.h"



Interface::Interface(QWidget* parent) : QWidget(parent) {
    start = new QPushButton(this);

    start->setGeometry(370, -6, 200, 70);
    start->setText("Start");
    start->setStyleSheet("QPushButton { background-color: #4CAF50; "
                         "color: white; border: none; padding: 5px 15px; "
                         "text-align: center; text-decoration: none; display: inline-block; "
                         "font-size: 35px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

    speed = new QLineEdit("100",this);
    speed->setGeometry(300, 0, 65, 60);
    speed->setStyleSheet("font-size: 12pt; background-color: #757575; border: 1px solid #757575; color: white; padding: 5px;");

    speed->setPlaceholderText("color: #B0B0B0;");

    helpLabel1 = new QLabel("Cкорость:",this);
    helpLabel1->setGeometry(150, 0, 150, 60);
    helpLabel1->setStyleSheet("font-size: 12pt; color: white;");

    helpLabel2 = new QLabel("При частоте зондирования 0.1, скорость рекомендуется не более 200 ед.",this);
    helpLabel2->setGeometry(40, 50, 750, 70);

    connect(start, &QPushButton::clicked, this, &Interface::runCar);
}



void Interface::setPainter(Painter* p) {
    pow = p;
}



Interface::~Interface() {
    delete start;
    delete speed;
}



void Interface::runCar() {
    if(pow->started){
        start->setText("Start");
    }
    else{
        start->setText("Return");
    }
    int valueSpeed = speed->text().toInt();
    pow->setSpeed(valueSpeed);
    pow->started = !pow->started;
    pow->c->setPos(QVector2D(pow->width() / 2, pow->height() / 2 - pow->r->getR2() - pow->r->getWidth() / 2));
    pow->c->setRotate(0);
}
