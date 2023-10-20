#include "interface.h"
#include "number.h"
#include "matrix.h"
#include <iostream>
#include <QString>



TInterface::TInterface(QWidget *parent): QWidget(parent) {

   setWindowTitle("Practical № 3");
   setFixedSize(450, 550);

   name_a = new QLabel("a =", this);
   name_a->setGeometry(70, 40, 30, 25);
   a_num = new QLineEdit("0", this);
   a_num->setGeometry(110, 20, 50, 25);
   delimeter_a = new QLabel("_____", this);
   delimeter_a->setGeometry(110, 28, 50, 25);
   a_den = new QLineEdit("0", this);
   a_den->setGeometry(110, 60, 50, 25);

   name_b = new QLabel("b =", this);
   name_b->setGeometry(250, 40, 30, 25);
   b_num = new QLineEdit("0", this);
   b_num->setGeometry(290, 20, 50, 25);
   delimeter_b = new QLabel("_____", this);
   delimeter_b->setGeometry(290, 28, 50, 25);
   b_den = new QLineEdit("0", this);
   b_den->setGeometry(290, 60, 50, 25);

   name_c = new QLabel("c =", this);
   name_c->setGeometry(70, 130, 30, 25);
   c_num = new QLineEdit("0", this);
   c_num->setGeometry(110, 110, 50, 25);
   delimeter_c = new QLabel("_____", this);
   delimeter_c->setGeometry(110, 118, 50, 25);
   c_den = new QLineEdit("0", this);
   c_den->setGeometry(110, 150, 50, 25);

   name_d = new QLabel("d =", this);
   name_d->setGeometry(250, 130, 30, 25);
   d_num = new QLineEdit("0", this);
   d_num->setGeometry(290, 110, 50, 25);
   delimeter_d = new QLabel("_____", this);
   delimeter_d->setGeometry(290, 118, 50, 25);
   d_den = new QLineEdit("0", this);
   d_den->setGeometry(290, 150, 50, 25);

   matrix = new QPushButton("matrix", this);
   matrix->setGeometry(10, 490, 100, 40);
   transpose = new QPushButton("transpose", this);
   transpose->setGeometry(120, 490, 100, 40);
   determinant = new QPushButton("det.", this);
   determinant->setGeometry(230, 490, 100, 40);
   rank = new QPushButton("rank", this);
   rank->setGeometry(340, 490, 100, 40);

   output = new QLabel(this);
   output->setGeometry(160, 300, 200, 80);

   connect(matrix, SIGNAL(pressed()), this, SLOT(onMatrix()));
   connect(determinant, SIGNAL(pressed()), this, SLOT(onCalculateDet()));
   connect(rank, SIGNAL(pressed()), this, SLOT(onCalculateRank()));
   connect(transpose, SIGNAL(pressed()), this, SLOT(onTransposeMatrix()));
}


TInterface::~TInterface(){

    delete name_a;
    delete delimeter_a;
    delete a_num;
    delete a_den;

    delete name_b;
    delete delimeter_b;
    delete b_num;
    delete b_den;

    delete name_c;
    delete delimeter_c;
    delete c_num;
    delete c_den;

    delete name_d;
    delete delimeter_d;
    delete d_num;
    delete d_den;

}



void TInterface::onMatrix(){

    number a(a_num->text().toInt(), a_den->text().toInt());
    number b(b_num->text().toInt(), b_den->text().toInt());
    number c(c_num->text().toInt(), c_den->text().toInt());
    number d(d_num->text().toInt(), d_den->text().toInt());

    TMatrix matrix;
    matrix.inputMatrix(a, b, c, d);

    output->setText(QString("[" + QString::number(a.getNumerator()) + "/" + QString::number(a.getDenominator()) + "] ["
                            + QString::number(b.getNumerator()) + "/" + QString::number(b.getDenominator()) + "]\n") + "["
                            + QString::number(c.getNumerator()) + "/" + QString::number(c.getDenominator()) + "] ["
                            + QString::number(d.getNumerator()) + "/" + QString::number(d.getDenominator()) + "]\n");
}



void TInterface::onCalculateDet() {

    number a(a_num->text().toInt(), a_den->text().toInt());
    number b(b_num->text().toInt(), b_den->text().toInt());
    number c(c_num->text().toInt(), c_den->text().toInt());
    number d(d_num->text().toInt(), d_den->text().toInt());

    if(a.getNumerator() == 0 || a.getDenominator() == 0 || b.getNumerator() == 0 || b.getDenominator() == 0 ||
       c.getNumerator() == 0 || c.getDenominator() == 0 || d.getNumerator() == 0 || d.getDenominator() == 0){
       output->setText("Error");
    }
    else{
       TMatrix matrix;
       matrix.inputMatrix(a, b, c, d);

       number det = matrix.calculateDet();

       QString result = "Determinant: \n" + QString::number(det.getNumerator()) + "/" + QString::number(det.getDenominator());
       output->setText(result);
    }
}



void TInterface::onCalculateRank() {

    number a(a_num->text().toInt(), a_den->text().toInt());
    number b(b_num->text().toInt(), b_den->text().toInt());
    number c(c_num->text().toInt(), c_den->text().toInt());
    number d(d_num->text().toInt(), d_den->text().toInt());

    TMatrix matrix;
    matrix.inputMatrix(a, b, c, d);

    int rank = matrix.calculateRank();

    output->setText("Rank: \n" + QString::number(rank));

}



void TInterface::onTransposeMatrix(){

    number a(a_num->text().toInt(), a_den->text().toInt());
    number b(b_num->text().toInt(), b_den->text().toInt());
    number c(c_num->text().toInt(), c_den->text().toInt());
    number d(d_num->text().toInt(), d_den->text().toInt());

    TMatrix matrix;
    matrix.inputMatrix(a, b, c, d);

    output->setText(QString("[" + QString::number(a.getNumerator()) + "/" + QString::number(a.getDenominator()) + "] ["
                           + QString::number(c.getNumerator()) + "/" + QString::number(c.getDenominator()) + "]\n") + "["
                           + QString::number(b.getNumerator()) + "/" + QString::number(b.getDenominator()) + "] ["
                           + QString::number(d.getNumerator()) + "/" + QString::number(d.getDenominator()) + "]\n");
}
