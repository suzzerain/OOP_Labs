#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QRadioButton>
#include <vector>


using namespace std;


class TInterface : public QWidget {
private:
    Q_OBJECT

    vector<vector<vector<QLabel*>>> del;
    vector<vector<vector<QLineEdit*>>> numbers;

    QPushButton *determinant;
    QPushButton *transpose;
    QPushButton *matrix;
    QPushButton *rank;
    QPushButton *refresh;

    QRadioButton *double_part;
    QRadioButton *complex_part;
    QRadioButton *rational_part;

    QLabel *output;
    QLabel *outputHelp1;

    int size;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
   void answer(QString);

private slots:
   void formRequest();

signals:
   void request(QString);
};

#endif // TINTERFACE_H
