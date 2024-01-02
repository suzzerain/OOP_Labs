#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QVector>
#include <QTimer>

#include "processor.h"
#include "task.h"


struct TSystemParam {
    int minTasksNumber;
    int maxTasksNumber;
    int curTasksNumber;

    int minProcessorsNumber;
    int maxProcessorsNumber;
    int curProcessorsNumber;

    int minExecutionTime;
    int maxExecutionTime;
};



class TSystem : public QObject {
    Q_OBJECT

    static TSystemParam defaultParam;
    TSystemParam currentParam;

    QVector<TProcessor> processors;
    QVector<TTask> tasks;
    QVector<TTask*> tasks_queue;

    QTimer* timer;

    int best_time;
    int time;

private slots:
    void tact();
    void add_to_queue(int);
    void add_to_list(int);
    void reset();
    void control(int);
    void changeProcessorsNumber(int);
    void changeTasksNumber(int);
    void task_to_processor(int);

signals:
    void show_current_tasks(QVector<TTask>);
    void show_current_processors(int);
    void remove_task_from_processor(int);
    void warning_signal(int);
    void finished();
    void current_time(int);
    void set_task_to_processor(int, TTask*);
    void new_record(int, QVector<TTask*>);

public:
    TSystem();
    ~TSystem();

    inline TSystemParam getParam() { return currentParam; };
    inline QVector<TTask> get_tasks() { return tasks; };
};

#endif // SYSTEM_H
