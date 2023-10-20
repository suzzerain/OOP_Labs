#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TInterface w;
    w.show();
    return a.exec();
}
