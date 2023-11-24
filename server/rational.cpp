#include "rational.h"
#include "common.h"
#include <cmath>

const int MATH_PRECISION = 7;

QChar TRational::SEPARATOR = separator;



TRational::TRational() : numerator(0), denominator(1) {}



TRational::TRational(const int& num) : numerator(num), denominator(1) {}



TRational::TRational(const int& num, const int& den) {
    numerator = num;
    denominator = den == 0 ? 1 : den;
}



TRational TRational::operator+(TRational other) const {
    TRational result;
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}



TRational TRational::operator-(TRational other) const {
    TRational result;
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}



TRational TRational::operator*(TRational other) const {
    TRational result;
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}



TRational TRational::operator/(TRational other) const {
    TRational result;
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    result.simplify();
    return result;
}



TRational TRational::simplify() {
    int a = numerator;
    int b = denominator;
    if(a && b != 0){
       while(b != 0){
           int c = b;
           b = a % b;
           a = c;
       }
       numerator /= a;
       denominator /= a;
    }
    else{
       numerator = a;
       denominator = b;
    }
    return *this;
}



QString& operator<<(QString& s, TRational r) {
    s += "[";
    s += QString().setNum(r.numerator);
    s += "/";
    s += QString().setNum(r.denominator);
    s += "]";
    return s;
}



TRational::TRational(const QByteArray& arr) {
    int p = (int) arr.indexOf(SEPARATOR);
    numerator = (int) arr.left(p).toInt();
    denominator = (int) arr.right(arr.length() - p - 1).toInt();
}



QByteArray& operator>> (QByteArray& arr, TRational& r) {
    int p = (int) arr.indexOf(TRational::SEPARATOR);
    p = (int) arr.indexOf(TRational::SEPARATOR, p + 1);
    if(p > 0){
        r = TRational(arr.left(p));
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}



bool TRational::operator== (TRational number) const {
    double left = double(numerator) / double(denominator);
    double right = double(number.numerator) / double(number.denominator);
    left = std::round(left * std::pow(10, MATH_PRECISION)) / std::pow(10, MATH_PRECISION);
    right = std::round(right * std::pow(10, MATH_PRECISION)) / std::pow(10, MATH_PRECISION);

    return left == right;
}



bool TRational::operator!= (TRational number) const {
    double left = double(numerator) / double(denominator);
    double right = double(number.numerator) / double(number.denominator);
    left = std::round(left * std::pow(10, MATH_PRECISION)) / std::pow(10, MATH_PRECISION);
    right = std::round(right * std::pow(10, MATH_PRECISION)) / std::pow(10, MATH_PRECISION);

    return left != right;
}
