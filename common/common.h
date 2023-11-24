#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages {
    MATRIX_REQUEST,
    MATRIX_ANSWER,
    TRANSPOSE_REQUEST,
    TRANSPOSE_ANSWER,
    DETERMINANT_REQUEST,
    DETERMINANT_ANSWER,
    RANK_REQUEST,
    RANK_ANSWER,
    ERROR
};

enum modes {
    DOUBLE_MODE = 1,
    COMPLEX_MODE,
    RATIONAL_MODE,
};

extern const QChar separator;

QString& operator<< (QString&, const QString&);

#endif // COMMON_H
