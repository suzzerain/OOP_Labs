#include "canvas.h"

TCanvas::TCanvas(TSample* f, QWidget *parent) : QWidget(parent) {
    s = f;
    setFixedSize(400,400);
}

TCanvas::~TCanvas(){}



void TCanvas::paintEvent(QPaintEvent*) {
    QPainter p;
    p.begin(this);
    s->draw(&p,rect(),Qt::green);
    p.end();
}
