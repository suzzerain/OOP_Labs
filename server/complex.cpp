#include "complex.h"
#include "common.h"

QChar Complex::SEPARATOR = separator;

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(const double& realPart){
    real = realPart;
    imag = 0;
}



Complex::Complex(const double& realPart, const double& imagPart){
    real = realPart;
    imag = imagPart;
}



Complex::Complex(const QByteArray& arr){
    int sepInd = (int) arr.indexOf(SEPARATOR);
    real = (int) arr.left(sepInd).toDouble();
    imag = (int) arr.right(arr.length() - sepInd - 1).toDouble();
}



std::istream& operator>> (std::istream& is, Complex& num){
    is >> num.real >> num.imag;
    return is;
}

std::ostream& operator<< (std::ostream& os, Complex num) {
    os << num.real << " + " << num.imag << "i";

    return os;
}


QString& operator<< (QString& os, Complex num) {
    os += "[";
    os += QString::number(num.real, 'f', 2) + " + " + QString::number(num.imag, 'f', 2) + "i";
    os += "]";
    return os;
}



QByteArray& operator>> (QByteArray& arr, Complex& num){
    int p = (int) arr.indexOf(Complex::SEPARATOR);
    p = (int) arr.indexOf(Complex::SEPARATOR, p + 1);
    num = Complex(arr.left(p));
    arr = arr.right(arr.length() - p - 1);
    return arr;
}



Complex Complex::operator+ (const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}



Complex Complex::operator- (const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}



Complex Complex::operator* (const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}



Complex Complex::operator/ (const Complex& other) const {
    Complex temp;
    temp.real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
    temp.imag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
    return temp;
}
