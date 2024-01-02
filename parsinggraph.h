#ifndef PARSINGGRAPH_H
#define PARSINGGRAPH_H


#include "graph.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

using namespace std;



class TParsing : public QWidget {
    friend class TSample;

    Q_OBJECT

    Graph* graph;

    string getPath();
    short parsingFile(const string&);
    void error(const short&);

public:
    TParsing(QWidget* parent = nullptr);
};

#endif // PARSINGGRAPH_H
