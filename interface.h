#ifndef INTERFACE_H
#define INTERFACE_H     // добавить в файлы другие графы


#include "parsinggraph.h"
#include "sample.h"

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

using namespace std;



class TInterface : public QWidget {
    Q_OBJECT

    QPushButton* btnUpdateFile;
    TSample* sample;
    QLabel* outputHelp1;
    QLabel* outputHelp2;

public:
    TInterface(TSample*, QWidget* parent = nullptr);
    ~TInterface() override;

public slots:
    void updateFile();

protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // INTERFACE_H
