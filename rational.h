#ifndef TRATIONAL_H
#define TRATIONAL_H

#include "number.h"
#include <iostream>
#include <QString>

using namespace std;

class TRational {
private:
    int numerator;
    int denominator;

public:
    TRational();
    TRational(int num, int den);

    TRational operator- (const TRational& other) const;
    TRational operator* (const TRational& other) const;

    int getNumerator() const;
    int getDenominator() const;
    void simplify();
};

#endif // TRATIONAL_H
