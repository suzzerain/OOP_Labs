#ifndef WIDGETS_H
#define WIDGETS_H

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QScrollBar>

#include "task.h"



class TTaskRecordView : public QWidget {
    Q_OBJECT

protected:
    QLabel* task_number;
    QLabel* execution_time;

    QGridLayout* l;

public:
    TTaskRecordView(int, int, QWidget *parent = 0);
    ~TTaskRecordView();
};



class TTaskView : public TTaskRecordView {
    Q_OBJECT

public:
    QPushButton* move_btn;

    TTaskView(int, int, QWidget *parent = 0);
    ~TTaskView();

private slots:
    void move_task();

signals:
    void reposition(TTaskView*);
};



class TWorkTaskView : public QWidget {
    Q_OBJECT

public:
    QLabel      *task_number_l;
    QLabel      *execution_time_l;
    QLabel      *time_l;
    QLabel      *current_time_l;
    QGridLayout *l;

    TWorkTaskView(int, int, int, QWidget *parent = 0);
    ~TWorkTaskView();
};



class TProcessorView : public QWidget {
    Q_OBJECT

public:
    QLabel* processor_image;
    QLabel* processor_number_l;

    QWidget* completed_tasks;
    QVBoxLayout* completed_tasks_vl;
    QScrollArea* scroll;

    TWorkTaskView* current_task;

    QVBoxLayout* vl;

    TProcessorView(int, QWidget *parent = 0);
    ~TProcessorView();

    void show_current(TTask*);
};

#endif // WIDGETS_H
