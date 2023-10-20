#ifndef TRATIONAL_H
#define TRATIONAL_H

#include "number.h"
#include <QString>


class TRational {
private:
    static QChar SEPARATOR;

    int numerator;
    int denominator;

public:
    TRational();
    TRational(int num, int den);
    TRational(const int&);
    TRational(const QByteArray&);

    TRational operator- (const TRational& other) const;
    TRational operator* (const TRational& other) const;

    int getNumerator() const;
    int getDenominator() const;
    void simplify();
    void setSeparator(QChar);

    //friend TRational operator QString();
    friend QString& operator<< (QString& s, TRational r);
    friend QByteArray& operator>> (QByteArray&, TRational&);
    operator QString();
};

#endif // TRATIONAL_H
