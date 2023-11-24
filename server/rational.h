#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>
#include <QString>
#include <cmath>
#include "common.h"

using namespace std;

class TRational {
public:
    static QChar SEPARATOR;

    int numerator;
    int denominator;

public:
    TRational();
    TRational(const int&);
    TRational(const int&, const int&);
    TRational(const QByteArray&);

    TRational operator- (TRational) const;
    TRational operator* (TRational) const;
    TRational operator+ (TRational) const;
    TRational operator/ (TRational) const;

    TRational simplify();

    friend QString& operator<< (QString&, TRational);
    friend QByteArray& operator>> (QByteArray&, TRational&);

    bool operator== (TRational number) const;
    bool operator!= (TRational number) const;
};

#endif // TRATIONAL_H
