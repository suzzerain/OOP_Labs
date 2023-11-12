#ifndef TRATIONAL_H
#define TRATIONAL_H

#include <iostream>
#include <QString>

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
};

#endif // TRATIONAL_H
