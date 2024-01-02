#ifndef INTERFACE_H
#define INTERFACE_H

#include "painter.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Interface : public QWidget {
    Q_OBJECT
    QPushButton* start;
    Painter* pow;

    QLabel* helpLabel1;
    QLabel* helpLabel2;
    QLineEdit* speed;

public:
    Interface(QWidget* parent = nullptr);
    ~Interface();

    void setPainter(Painter* p);

public slots:
    void runCar();
};

#endif // INTERFACE_H
