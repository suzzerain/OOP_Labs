#ifndef TASK_H
#define TASK_H


class TTask {
public:
    int task_number;
    int execution_time;
    int current_time;

    TTask();
    TTask(int, int, int);
    TTask(const TTask&);
    TTask& operator= (const TTask &);
};

#endif // TASK_H
