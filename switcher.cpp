#include "switcher.h"



TSwitcher::TSwitcher(TParsing* parsing) : TSample(parsing) {
    if(empty()){
        return;
    }
    index = 0;
}



void TSwitcher::change(TParsing* parsing) {
    TSample::change(parsing);
    index = 0;
}



void TSwitcher::update(bool rotate) {
    if(rotate){
       index++;
    }
    else{
       index--;

       if(index < 0){
          index += graph->size();
       }
    }
    index %= graph->size();
}



void TSwitcher::draw(QPainter* painter, QRect& rect) {
    if(empty()){
        return;
    }
    TSample::draw(painter, rect);

    int radius = 150;
    int vertR = 15;
    int angle = index * 360 / graph->size();

    double rad = qDegreesToRadians(static_cast<double>(angle));
    int dx = static_cast<int>(radius * qCos(rad));
    int dy = static_cast<int>(radius * qSin(rad));
    QPoint circlePoint = rect.center() + QPoint(dx, dy);
    painter->setBrush(Qt::red);
    painter->drawEllipse(circlePoint, vertR, vertR);

    vector<Vertex*> vertices = graph->getVertices();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 10, QFont::Bold));
    QRect textRect(circlePoint.x() - vertR, circlePoint.y() - vertR, 2*vertR, 2*vertR);
    painter->drawText(textRect, QChar(vertices[index]->getTitle()), QTextOption(Qt::AlignCenter));
}
