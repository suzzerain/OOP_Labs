#ifndef INTERFACE_H
#define INTERFACE_H


#include "parsinggraph.h"
#include "switcher.h"

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>

using namespace std;



class TInterface : public QWidget {
    Q_OBJECT

    QPushButton* btnUpdateFile;
    TSwitcher* sample;

    QLabel* outputHelp1;
    QLabel* outputHelp2;

public:
    TInterface(TSwitcher*, QWidget* parent = nullptr);
    ~TInterface() override;

public slots:
    void updateFile();

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
};

#endif // INTERFACE_H
