#ifndef SWITCHER_H
#define SWITCHER_H


#include "sample.h"


class TSwitcher : public TSample {

    int index;

public:
    TSwitcher(TParsing*);

    void change(TParsing*);
    void update(bool);
    void draw(QPainter*, QRect&);
};

#endif // SWITCHER_H
