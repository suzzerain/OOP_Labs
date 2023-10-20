#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    MATRIX_REQUEST = 1,
    MATRIX_ANSWER,
    PRINT_MATRIX_REQUEST,
    PRINT_ANSWER,
    DETERMINANT_REQUEST,
    DETERMINANT_ANSWER,

};

extern const QChar separator;

QString& operator<< (QString&, const QString&);

#endif // COMMON_H
