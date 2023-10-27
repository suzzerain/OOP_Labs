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
    TRational(int num, int den);
    TRational(const QByteArray&);

    TRational operator- (const TRational& other) const;
    TRational operator* (const TRational& other) const;

    static void setSeparator(QChar);

    int getNumerator() const;
    int getDenominator() const;
    void simplify();

    friend QString& operator<< (QString&, TRational);
    friend QByteArray& operator>> (QByteArray&, TRational&);
    operator QString();
};

#endif // TRATIONAL_H
