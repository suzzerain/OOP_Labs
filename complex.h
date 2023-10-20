#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>

using namespace std;



class TComplex {

private:
    double real, imag;

public:
    TComplex();
    TComplex(double realPart, double imagPart);

    TComplex operator+ (const TComplex& other) const;
    TComplex operator- (const TComplex& other) const;
    TComplex operator* (const TComplex& other) const;
    bool operator != (const TComplex& other) const {
        return (real != other.real) || (imag != other.imag);
    }

    friend ostream& operator << (ostream& os, const TComplex& complex);
    friend istream& operator >> (istream& is, TComplex& complex);
};

#endif // TCOMPLEX_H
