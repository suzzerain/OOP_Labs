#include "parsinggraph.h"
#include "switcher.h"
#include "interface.h"

#include <QApplication>


int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    TParsing parsing;
    TSwitcher sample(&parsing);
    TInterface interface(&sample);
    interface.show();

    return app.exec();
}
