#include "interface.h"
#include "common.h"



TInterface::TInterface(QWidget *parent): QWidget(parent) {

   setStyleSheet("background-color: #2E2E2E; color: #FFFFFF");
   setWindowTitle("Practical № 6");
   setFixedSize(600, 800);

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
   del.resize(size);

   for(int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
           numbers[i].resize(size);
           numbers[i][j].resize(2);
           del[i].resize(size);
           del[i][j].resize(2);

           numbers[i][j][0] = new QLineEdit("0", this);
           numbers[i][j][0]->setGeometry(100*j + 140, 75*i + 10, 25, 25);
           numbers[i][j][0]->setStyleSheet("background-color: #808080; color: #000000; border: 1 px solid #444444; }");

           del[i][j][0] = new QLabel("/",this);
           del[i][j][0]->setGeometry(100*j + 170, 75*i + 10, 10, 25);
           del[i][j][1] = new QLabel("",this);
           del[i][j][1]->setGeometry(100*j + 213, 75*i + 10, 10, 25);

           numbers[i][j][1] = new QLineEdit("0", this);
           numbers[i][j][1]->setGeometry(100*j + 185, 75*i + 10, 25, 25);
           numbers[i][j][1]->setStyleSheet("background-color: #808080; color: #000000; border: 1 px solid #444444; }");
       }
   }

   matrix = new QPushButton("matrix", this);
   matrix->setGeometry(0, 700, 150, 40);
   matrix->setStyleSheet("QPushButton { background-color: #4CAF50; "
                         "color: white; border: none; padding: 5px 15px; "
                         "text-align: center; text-decoration: none; display: inline-block; "
                         "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   transpose = new QPushButton("transpose", this);
   transpose->setGeometry(150, 700, 150, 40);
   transpose->setStyleSheet("QPushButton { background-color: #008CBA; "
                            "color: white; border: none; padding: 5px 15px; "
                            "text-align: center; text-decoration: none; display: inline-block; "
                            "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   determinant = new QPushButton("det.", this);
   determinant->setGeometry(300, 700, 150, 40);
   determinant->setStyleSheet("QPushButton { background-color: #f44336; "
                              "color: white; border: none; padding: 5px 15px; "
                              "text-align: center; text-decoration: none; display: inline-block;"
                              " font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   rank = new QPushButton("rank", this);
   rank->setGeometry(450, 700, 150, 40);
   rank->setStyleSheet("QPushButton { background-color: #555555; "
                       "color: white; border: none; padding: 5px 15px; "
                       "text-align: center; text-decoration: none; display: inline-block; "
                       "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   refresh = new QPushButton("init. type",this);
      refresh->setGeometry(220, 600, 150, 40);
      refresh->setStyleSheet("QPushButton { background-color: #00FF00; "
                            "color: black; border: none; padding: 5px 15px; "
                            "text-align: center; text-decoration: none; display: inline-block; "
                            "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

   double_part = new QRadioButton("double", this);
   double_part->setGeometry(90, 650, 150, 40);

   complex_part = new QRadioButton("complex", this);
   complex_part->setGeometry(240, 650, 150, 40);

   rational_part = new QRadioButton("rational", this);
   rational_part->setGeometry(390, 650, 150, 40);
   rational_part->setChecked(true);

   QString radioStyle = "QRadioButton {"
                        "   color: white;"
                        "}"
                        "QRadioButton::indicator {"
                        "   border: 2px solid white;"
                        "   width: 15px;"
                        "   height: 15px;"
                        "   border-radius: 7px;"
                        "}"
                        "QRadioButton::indicator:checked {"
                        "   background-color: white;"
                        "   border: 2px solid white;"
                        "}";

   double_part->setStyleSheet(radioStyle);
   complex_part->setStyleSheet(radioStyle);
   rational_part->setStyleSheet(radioStyle);

   output = new QLabel("", this);
   output->setGeometry(100, 450, 600, 100);
   output->setStyleSheet("QLabel { backgroung-color : (black; color : white; }");


   outputHelp1 = new QLabel("ВНИМАНИЕ! После установки флага выбранного типа\n данных произвести инициализацию(init. type)", this);
   outputHelp1->setGeometry(0, 740, 600, 50);
   outputHelp1->setStyleSheet("QLabel { backgroung-color : (black; color: white; }");

   connect(determinant, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(matrix, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(rank, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(transpose, SIGNAL(pressed()), this, SLOT(formRequest()));
   connect(refresh, SIGNAL(pressed()), this, SLOT(formRequest()));
}


TInterface::~TInterface(){
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

    delete double_part;
    delete complex_part;
    delete rational_part;

    delete output;
    delete outputHelp1;
}



void TInterface::formRequest(){
    QString msg;
    msg += QString::number(size);
    msg += separator;

    if(!double_part->isChecked()){
        if(rational_part->isChecked()){
            msg << QString().setNum(RATIONAL_MODE);
            bool errorFlag = false;
            for(auto &rows : numbers){
                for(auto &cols : rows){
                    for(auto &el : cols){
                        msg << el->text();
                        if(cols[1]->text() == "0"){
                            errorFlag=true;
                        }
                    }
                }
            }
            if (errorFlag){
                msg << QString().setNum(ERROR);
                emit request(msg);
            }
        }
        else{
            msg << QString().setNum(COMPLEX_MODE);
            for(auto &rows : numbers){
                for(auto &cols : rows){
                    for(auto &el : cols){
                        msg << el->text();
                    }
                }
            }
        }
    }
    else{
        msg << QString().setNum(DOUBLE_MODE);
        for(auto &rows : numbers){
            for(auto &cols : rows){
                msg << cols[0]->text();
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
    if(btn == refresh){
        if(complex_part->isChecked()){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    numbers[i][j][0]->setGeometry(100*j + 140, 75*i + 10, 25, 25);
                    numbers[i][j][1]->setGeometry(100*j + 185, 75*i + 10, 25, 25);
                    del[i][j][0]->setText("+");
                    del[i][j][1]->setText("i");

                }
            }

        }
        else if(rational_part->isChecked()){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    numbers[i][j][0]->setGeometry(100*j + 140, 75*i + 10, 25, 25);
                    numbers[i][j][1]->setGeometry(100*j + 185, 75*i + 10, 25, 25);
                    del[i][j][0]->setText("/");
                    del[i][j][1]->setText("");

                }
            }

        }
        else if(double_part->isChecked()){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    del[i][j][0]->setText("");
                    del[i][j][1]->setText("");
                    numbers[i][j][1]->setGeometry(1000, 1000, 25, 25);
                    numbers[i][j][0]->setGeometry(65*j + 140, 80*i + 20, 30, 25);
                }
            }
        }

    }
    if(btn!=refresh){
       emit request(msg);
    }
}



void TInterface::answer(QString msg){
    QString text;

    int p = (int) msg.indexOf(separator);
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
