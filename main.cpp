#include <QApplication>

#include "interface.h"
#include "system.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TSystem s;
    TMainWindow w(&s);
    w.showMaximized();
    return a.exec();
}
