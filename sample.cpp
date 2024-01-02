#include "sample.h"


TSample::TSample(TParsing* parsing) {
    graph = parsing->graph;
}


void TSample::change(TParsing* parsing) {
    graph = parsing->graph;
}


bool TSample::empty() {
    return graph->empty();
}


void TSample::draw(QPainter* painter, QRect& rect) {
    if(empty()){
        return;
    }
    int radius = 150;
    int vertR = 20;
    vector<Vertex*> vertices = graph->getVertices();
    map<Vertex*, QPoint> verticesPos;
    int step = 360 / graph->size();

    for(int i = 0, angle = 0; i < graph->size(); ++i, angle += step){
        double rad = qDegreesToRadians(static_cast<double>(angle));
        int dx = static_cast<int>(radius * qCos(rad));
        int dy = static_cast<int>(radius * qSin(rad));

        QPoint circlePoint = rect.center() + QPoint(dx, dy);
        verticesPos[vertices[i]] = circlePoint;
        painter->setBrush(Qt::blue);
        painter->drawEllipse(circlePoint, vertR, vertR);

        painter->setPen(QPen(Qt::gray, 3));
        painter->setFont(QFont("Helvetica", 12, QFont::Bold));

        QRect textRect(circlePoint.x() - vertR, circlePoint.y() - vertR, 2*vertR, 2*vertR);
        painter->drawText(textRect, QChar(vertices[i]->getTitle()), QTextOption(Qt::AlignCenter));
    }
    painter->setPen(QPen(Qt::black, 3));
    for(int i = 0; i < graph->size(); ++i){
        vector<Vertex*> neighbors = vertices[i]->getNeighbourVertex();
        for(int j = 0; j < neighbors.size(); ++j){
            QPointF p1 = verticesPos[vertices[i]];
            QPointF p2 = verticesPos[neighbors[j]];
            QPointF v = p2 - p1;
            double length = sqrt(v.x() * v.x() + v.y() * v.y());
            QPointF offset = QPoint(v.x() / length * vertR, v.y() / length * vertR);
            painter->drawLine(p1 + offset, p2 - offset);

            double size = 8.0;
            QPointF arrowTop = p2 - offset;
            QPointF arrowDir = (v / length) * size;
            QPointF arrowL = arrowTop - arrowDir + QPointF(arrowDir.y(), -arrowDir.x());
            QPointF arrowR = arrowTop - arrowDir + QPointF(-arrowDir.y(), arrowDir.x());
            painter->drawPolygon(QPolygonF() << arrowTop << arrowL << arrowR);
        }
    }
}
