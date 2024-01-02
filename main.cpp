#include "parsinggraph.h"
#include "sample.h"
#include "interface.h"

#include <QApplication>


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    TParsing parsing;
    TSample sample(&parsing);
    TInterface interface(&sample);
    interface.show();

    return app.exec();
}
