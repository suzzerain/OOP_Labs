#include "application.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    TApplication a(argc, argv);
    return a.exec();
}
