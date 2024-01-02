#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QTimer>
#include <QVector>
#include <QObject>

#include "task.h"


class TProcessor : public QObject {
    Q_OBJECT

public:
    int processor_number;
    bool active;

    TTask* current_task;

public:
    TProcessor();
    TProcessor(int);
    TProcessor(const TProcessor&);
    TProcessor& operator=(const TProcessor&);

    void current_task_complete();

public slots:
    void tact();
    void set_current_task(TTask*);

signals:
    void task_request(int);
};


#endif // PROCESSOR_H
