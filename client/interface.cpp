#include "interface.h"
#include "common.h"



TInterface::TInterface(QWidget *parent): QWidget(parent) {

   setStyleSheet("background-color: #2E2E2E; color: #FFFFFF");
   setWindowTitle("Practical № 5");
   setFixedSize(600, 700);

   bool correct;
   QString input = QInputDialog::getText(this, "Matrix size", "Enter size(max.4): ", QLineEdit::Normal, "", &correct);
   if(correct && !input.isEmpty()){
       size = input.toInt(&correct);

       if(size > 4){
           QMessageBox::critical(this, "Error", "Size is big");
           return;
       }
       if(!correct){
           QMessageBox::critical(nullptr, "Error", "Wrong input");
           return;
       }
   }

   numbers.resize(size);
   del.resize(size*size);

   for(int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
           numbers[i].resize(size);
           numbers[i][j].resize(2);

           numbers[i][j][0] = new QLineEdit("0", this);
           numbers[i][j][0]->setGeometry(65*j + 140, 80*i + 20, 50, 25);
           numbers[i][j][0]->setStyleSheet("background-color: #808080; color: #000000; border: 1 px solid #444444; }");

           del[i+j] = new QLabel("_____", this);
           del[i+j]->setGeometry(65*j + 140, 80*i + 28, 50, 25);

           numbers[i][j][1] = new QLineEdit("0", this);
           numbers[i][j][1]->setGeometry(65*j + 140, 80*i + 60, 50, 25);
           numbers[i][j][1]->setStyleSheet("background-color: #808080; color: #000000; border: 1 px solid #444444; }");

           del[i+j]->setStyleSheet("QLabel { background-color: transparent; color: #FFFFFF}");
       }
   }

   matrix = new QPushButton("matrix", this);
   matrix->setGeometry(0, 650, 150, 40);
   matrix->setStyleSheet("QPushButton { background-color: #4CAF50; "
                         "color: white; border: none; padding: 5px 15px; "
                         "text-align: center; text-decoration: none; display: inline-block; "
                         "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   transpose = new QPushButton("transpose", this);
   transpose->setGeometry(150, 650, 150, 40);
   transpose->setStyleSheet("QPushButton { background-color: #008CBA; "
                            "color: white; border: none; padding: 5px 15px; "
                            "text-align: center; text-decoration: none; display: inline-block; "
                            "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   determinant = new QPushButton("det.", this);
   determinant->setGeometry(300, 650, 150, 40);
   determinant->setStyleSheet("QPushButton { background-color: #f44336; "
                              "color: white; border: none; padding: 5px 15px; "
                              "text-align: center; text-decoration: none; display: inline-block;"
                              " font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   rank = new QPushButton("rank", this);
   rank->setGeometry(450, 650, 150, 40);
   rank->setStyleSheet("QPushButton { background-color: #555555; "
                       "color: white; border: none; padding: 5px 15px; "
                       "text-align: center; text-decoration: none; display: inline-block; "
                       "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   output = new QLabel("", this);
   output->setGeometry(120, 450, 400, 100);
   output->setStyleSheet("QLabel { backgroung-color : (black; color : white; }");

   connect(determinant, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(matrix, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(rank, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(transpose, SIGNAL(pressed()), this, SLOT(formRequest()));
}


TInterface::~TInterface(){

    for(auto &del : del){
        delete del;
    }
    for(auto &rows : numbers){
        for(auto &cols : rows){
            for(auto &el : cols){
                delete el;
            }
        }
    }

    delete matrix;
    delete determinant;
    delete rank;
    delete transpose;

    delete output;
}



void TInterface::formRequest(){
    QString msg;
    msg += QString::number(size);
    msg += separator;
    for(auto &rows : numbers){
        for(auto &cols : rows){
            for(auto &el : cols){
                msg << el->text();
            }
        }
    }


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
    msg = msg.mid(p + 1, msg.length() - p - 2);

    switch(t){
       case MATRIX_ANSWER: {
          text = "matrix:\n";
          text = msg;
          output->setText(text);
          break;
       }
       case TRANSPOSE_ANSWER: {
          text = "transpose:\n";
          text = msg;
          output->setText(text);
          break;
       }
       case DETERMINANT_ANSWER: {
          text = "determinant:\n";
          text += msg;
          output->setText(text);
          break;
       }
       case RANK_ANSWER: {
          text = "rank:\n";
          text += msg;
          output->setText(text);
          break;
       }
       case ERROR: {
          text = "ERROR:\n'0' in denominator";
          output->setText(text);
       }
       default: {
          break;
       }
    }
}

