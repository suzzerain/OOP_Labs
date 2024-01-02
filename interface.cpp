#include "interface.h"
#include "parsinggraph.h"



TInterface::TInterface(TSample* sample, QWidget* parent) : QWidget(parent) {
    setWindowTitle("Practical № 7");
    setFixedSize(500, 550);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53, 53, 53));
    palette.setColor(QPalette::WindowText, Qt::white);
    setPalette(palette);

    this->sample = sample;

    btnUpdateFile = new QPushButton("Choice", this);
    btnUpdateFile->setGeometry(350, 470, 150, 48);
    btnUpdateFile->setStyleSheet("QPushButton { background-color: #555555; "
                                 "color: white; border: none; padding: 5px 15px; "
                                 "text-align: center; text-decoration: none; display: inline-block; "
                                 "font-size: 16px; margin: 4px 2px; cursor: pointer; border-radius: 4px; }");

    outputHelp1 = new QLabel("Click to change file ->", this);
    outputHelp1->setGeometry(130, 473, 220, 38);
    outputHelp1->setStyleSheet("QLabel { backgroung-color : black; color : white; }");

    outputHelp2 = new QLabel("DIRECTED GRAPH", this);
    outputHelp2->setGeometry(170, 10, 200, 38);
    outputHelp2->setStyleSheet("QLabel { backgroung-color : black; color : white; }");

    connect(btnUpdateFile, SIGNAL(pressed()), this, SLOT(updateFile()));
}



TInterface::~TInterface() {
    delete btnUpdateFile;
    delete sample;
    delete outputHelp1;
    delete outputHelp2;
}


void TInterface::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    QRect rect(0, 0, 500, 510);

    painter.setPen(QPen(Qt::white, 3));

    sample->draw(&painter, rect);
    painter.end();
}



void TInterface::updateFile() {
    TParsing parsing;
    sample->change(&parsing);
    if(sample->empty()){
        close();
    }
}
