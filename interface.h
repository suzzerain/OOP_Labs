#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QVector>
#include <QScrollArea>

#include "widgets.h"
#include "system.h"

class TSettingsWindow : public QWidget {
    Q_OBJECT

    QLabel* header;

    QLabel* processors_number_l;
    QSpinBox* processors_number;
    QPushButton* set_processors_number_btn;

    QLabel* tasks_number_l;
    QSpinBox* tasks_number;
    QPushButton* generate_tasks_btn;

public:
    TSettingsWindow(TSystemParam, QWidget *parent = 0);
    ~TSettingsWindow();

public slots:
    void generate_tasks();
    void set_processors_number();
    void block();

signals:
    void generate(int);
    void set(int);
};



class TControlWindow : public QWidget {
    Q_OBJECT

    QLabel* header;

    QPushButton* start_btn;
    QPushButton* reset_btn;

public:
    TControlWindow(QWidget *parent = 0);
    ~TControlWindow();

public slots:
    void start();
    void reset();
    void block();

signals:
    void start_signal(int);
    void reset_system(int);
};




class TProcessorsWindow : public QWidget {
    Q_OBJECT

    QGridLayout* l;

    QLabel* header;

    QPushButton* processors_widget_btn;
    QPushButton* record_widget_btn;

    QWidget* processors_widget;

    QVBoxLayout* vl;

    QLabel* current_time_l;
    QHBoxLayout* hl;

    QWidget* record_widget;
    QLabel* record_time_header;
    QLabel* record_queue_header;
    QGridLayout* rl;
    QScrollArea* record_scroll;
    QWidget* record;
    QVBoxLayout* vlr;

    QVector<TProcessorView*> processors;

public:
    TProcessorsWindow(QWidget *parent = 0);
    ~TProcessorsWindow();

public slots:
    void show_processors_widget();
    void show_record_widget();
    void clear(int);
    void show_processors(int);
    void show_current_time(int);
    void set_current_task(int, TTask*);
    void show_new_record(int, QVector<TTask*>);
};




class TTasksWindow : public QWidget {
    Q_OBJECT

    QGridLayout* l;

    QLabel* tasks_list_header;

    QScrollArea* tasks_list_scroll;
    QWidget* tasks_list_widget;

    QLabel* tasks_queue_header;

    QScrollArea* tasks_queue_scroll;
    QWidget* tasks_queue_widget;

    QVBoxLayout* vll;
    QVBoxLayout* vlq;

    QVector<TTaskView*> tasks;

public:
    TTasksWindow(QWidget *parent = 0);
    ~TTasksWindow();

public slots:
    void show_current_tasks(QVector<TTask>);
    void add_to_queue(TTaskView*);
    void add_to_list(TTaskView*);
    void clear_tasks();

signals:
    void to_list(int);
    void to_queue(int);
};




class TMainWindow : public QWidget {
    Q_OBJECT

    TSystem* system;

    QGridLayout* l;

    TProcessorsWindow  *pw;
    TSettingsWindow    *sw;
    TTasksWindow       *tw;
    TControlWindow     *cw;

public:
    TMainWindow(TSystem*, QWidget *parent = 0);
    ~TMainWindow();

public slots:
    void warning(int);
    void completed();
};

#endif // INTERFACE_H
