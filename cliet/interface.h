#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>



class TInterface : public QWidget {

    Q_OBJECT

    QLabel *name_a, *delimeter_a;
    QLineEdit *a_num, *a_den;

    QLabel *name_b, *delimeter_b;
    QLineEdit *b_num, *b_den;

    QLabel *name_c, *delimeter_c;
    QLineEdit *c_num, *c_den;

    QLabel *name_d, *delimeter_d;
    QLineEdit *d_num, *d_den;

    QPushButton *determinant;
    QPushButton *transpose;
    QPushButton *matrix;
    QPushButton *rank;

    QLabel *output;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
    void answer(QString);

private slots:
   void formRequest();

signals:
   void request(QString);
};

#endif // TINTERFACE_H
