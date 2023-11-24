#ifndef DOUBLE_H
#define DOUBLE_H

#include <QString>
#include "common.h"

inline QString& operator<< (QString& s, double numb){
    s += "[";
    s += QString().setNum(numb);
    s += "]";
    return s;
}


inline QByteArray& operator>> (QByteArray& arr, double& numb){
    int p = (int) arr.indexOf(separator);
    numb = arr.left(p).toDouble();
    arr = arr.right(arr.length() - p - 1);
    return arr;
}

#endif // DOUBLE_H
