#include "window.h"

Window::Window(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(800, 600);

    QPalette dark;
    dark.setColor(QPalette::Window, QColor(53, 53, 53));
    dark.setColor(QPalette::WindowText, Qt::white);
    dark.setColor(QPalette::Button, QColor(53, 53, 53));
    dark.setColor(QPalette::ButtonText, Qt::white);

    this->setPalette(dark);

    pow = new Painter(this);
    i = new Interface(this);
    i->setPainter(pow);

    pow->setGeometry(0, 0, 800, 500);
    i->setGeometry(0, 500, 800, 100);
}



Window::~Window() {
    delete pow;
    delete i;
}
