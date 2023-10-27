#include "number.h"
#include "common.h"



QChar TRational::SEPARATOR = separator;



TRational::TRational() : numerator(0), denominator(1) {}



TRational::TRational(int num, int den) : numerator(num), denominator(den) {}



TRational TRational::operator-(const TRational& other) const {
    number result;
    result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    result.denominator = this->denominator * other.denominator;
    result.simplify();
    return result;
}



TRational TRational::operator*(const TRational& other) const {
    number result;
    result.numerator = this->numerator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    result.simplify();
    return result;
}



int TRational::getNumerator() const {
    return numerator;
}



int TRational::getDenominator() const {
    return denominator;
}



void TRational::simplify() {
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
}



TRational::operator QString() {
    QString s = "[";
    s += QString::number(numerator);
    s += "/";
    s += QString::number(denominator);
    s += "]";
    return s;
}



QString& operator<<(QString& s, TRational r) {
    s += "[";
    s += QString::number(r.numerator);
    s += "/";
    s += QString::number(r.denominator);
    s += "]";
    return s;
}



TRational::TRational(const QByteArray& arr) {
    int p = arr.indexOf(SEPARATOR);
    numerator = arr.left(p).toInt();
    denominator = arr.right(arr.length() - p - 1).toInt();
}



QByteArray& operator>>(QByteArray& arr, TRational& r) {
    int p = arr.indexOf(TRational::SEPARATOR);
    p = arr.indexOf(TRational::SEPARATOR, p + 1);
    if(p > 0){
        r = TRational(arr.left(p));
        arr = arr.right(arr.length() - p - 1);
    }
    return arr;
}



void TRational::setSeparator(QChar ch) {
    SEPARATOR = ch;
}
