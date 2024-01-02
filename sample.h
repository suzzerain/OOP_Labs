#ifndef SAMPLE_H
#define SAMPLE_H

#include "parsinggraph.h"

#include <iostream>
#include <QPainter>
#include <QtMath>
#include <map>

using namespace std;



class TSample {
    Graph* graph;

public:
    TSample(TParsing*);
    void change(TParsing*);

    bool empty();
    void draw(QPainter*, QRect&);
};


#endif // SAMPLE_H
