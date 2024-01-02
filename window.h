#ifndef WINDOW_H
#define WINDOW_H

#include "interface.h"
#include "painter.h"

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QPainter>

class Window : public QMainWindow {
    Q_OBJECT
    Painter* pow;
    Interface *i;

public:
    Window(QWidget *parent = nullptr);
    ~Window();
};

#endif // WINDOW_H
