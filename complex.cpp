#include "complex.h"

TComplex::TComplex() : real(0.0), imag(0.0) {}



TComplex::TComplex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}



TComplex TComplex::operator+ (const TComplex& other) const {
    return TComplex(real + other.real, imag + other.imag);
}



TComplex TComplex::operator- (const TComplex& other) const {
    return TComplex(real - other.real, imag - other.imag);
}



TComplex TComplex::operator* (const TComplex& other) const {
    return TComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}



ostream& operator << (ostream& os, const TComplex& complex) {
    if(complex.imag < 0){
        os << complex.real << complex.imag << "i";
    }
    else{
       os << complex.real << "+" << complex.imag << "i";
    }
    return os;
}



istream& operator >> (istream& is, TComplex& complex) {
    cout << "Enter real part(number): ";
    is >> complex.real;
    cout << "Enter imag part(number): ";
    is >> complex.imag;
    return is;
}
