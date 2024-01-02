#ifndef SAMPLE_H
#define SAMPLE_H

#include "parsinggraph.h"

#include <iostream>
#include <QPainter>
#include <QtMath>
#include <map>

using namespace std;



class TSample {
protected:
    Graph* graph;

public:
    TSample(TParsing*);

    virtual void change(TParsing*);
    bool empty();
    virtual void draw(QPainter*, QRect&);
};


#endif // SAMPLE_H
