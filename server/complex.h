#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <QString>

using namespace std;

class Complex {
private:
    static QChar SEPARATOR;
    double real, imag;

public:
    Complex();
    Complex(const double&);
    Complex(const double&, const double&);
    Complex(const QByteArray&);

    friend istream& operator>> (istream&, Complex&);
    friend QByteArray& operator>> (QByteArray&, Complex&);

    friend ostream& operator<< (ostream&, Complex);
    friend QString& operator<< (QString&, Complex);

    Complex operator+ (const Complex& other) const;
    Complex operator- (const Complex& other) const;
    Complex operator* (const Complex& other) const;
    Complex operator/ (const Complex& other) const;

    bool operator != (const Complex& other) const {
        return (real != other.real) || (imag != other.imag);
    }

    bool operator== (const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
};

#endif // COMPLEX_H
