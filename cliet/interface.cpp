#include "interface.h"
#include "common.h"



TInterface::TInterface(QWidget *parent): QWidget(parent) {

   setWindowTitle("Practical № 4");
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
   matrix_output_1 = new QLabel(this);
   matrix_output_1->setGeometry(160, 320, 200, 80);
   matrix_output_2 = new QLabel(this);
   matrix_output_2->setGeometry(160, 340, 200, 80);

   connect(determinant, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(matrix, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(rank, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(transpose, SIGNAL(pressed()), this, SLOT(formRequest()));
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

    delete matrix;
    delete determinant;
    delete rank;
    delete transpose;

    delete output;
    delete matrix_output_1;
    delete matrix_output_2;
}



void TInterface::formRequest(){
    QString msg;
    msg << a_num->text() << a_den->text();
    msg << b_num->text() << b_den->text();
    msg << c_num->text() << c_den->text();
    msg << d_num->text() << d_den->text();

    QPushButton *btn = (QPushButton*)sender();
    if(btn == matrix){
        msg << QString().setNum(MATRIX_REQUEST);
    }
    if(btn == transpose){
        msg << QString().setNum(TRANSPOSE_REQUEST);
    }
    if(btn == determinant){
        msg << QString().setNum(DETERMINANT_REQUEST);
    }
    if(btn == rank){
        msg << QString().setNum(RANK_REQUEST);
    }
    emit request(msg);
}



void TInterface::answer(QString msg){
    QString text;

    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p + 1, msg.length() - p - 1);

    switch(t){
       case MATRIX_ANSWER: {
          text = "matrix:\n";
          output->setText(text);

          text = msg.mid(0, msg.length()/2);
          matrix_output_1->setText(text);

          text = msg.mid(msg.length() / 2);
          matrix_output_2->setText(text);
          break;
       }
       case TRANSPOSE_ANSWER: {
          text = "transpose:\n";
          output->setText(text);

          text = msg.mid(0, msg.length() / 2);
          matrix_output_1->setText(text);

          text = msg.mid(msg.length() / 2);
          matrix_output_2->setText(text);
          break;
       }
       case DETERMINANT_ANSWER: {
          matrix_output_1->setText("");
          matrix_output_2->setText("");

          text = "determinant:\n";
          text += msg;
          output->setText(text);
          break;
       }
       case RANK_ANSWER: {
          matrix_output_1->setText("");
          matrix_output_2->setText("");

          text = "rank:\n";
          text += msg;
          output->setText(text);
          break;
       }
       case ERROR: {
          matrix_output_1->setText("");
          matrix_output_2->setText("");

          text = "ERROR:\n'0' in denominator";
          output->setText(text);
       }
       default: {
          break;
       }
    }
}
