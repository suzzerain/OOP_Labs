#include "task.h"

#include <QRandomGenerator>



TTask::TTask(){}

TTask::TTask(int number, int minTime, int maxTime) {
    task_number = number;

    QRandomGenerator *generator = QRandomGenerator::global();
    execution_time = generator->bounded(minTime, maxTime + 1);

    current_time = 0;
}



TTask::TTask(const TTask& m) {
    *this = m;
}



TTask& TTask::operator=(const TTask& m) {
    task_number = m.task_number;
    execution_time = m.execution_time;
    current_time = m.current_time;
    return *this;
}
