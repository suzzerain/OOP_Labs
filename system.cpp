#include "system.h"



TSystemParam TSystem::defaultParam = {6, 32, 16,
                                      1,  5,  3,
                                      2,  8};

TSystem::TSystem() : QObject() {
    currentParam = defaultParam;

    for(int i = 0; i < currentParam.curProcessorsNumber; i++) {
        TProcessor processor = TProcessor(i + 1);
        processors.push_back(processor);
        tasks_queue.push_back(nullptr);
    }
    for(int i = 0; i < currentParam.curProcessorsNumber; i++){
        connect(&(processors[i]), SIGNAL(task_request(int)), this, SLOT(task_to_processor(int)));
    }
    for(int i = 0; i < currentParam.curTasksNumber; i++){
        TTask task(i + 1, currentParam.minExecutionTime, currentParam.maxExecutionTime);
        tasks.push_back(task);
    }

    timer = new QTimer();
    timer->setTimerType(Qt::PreciseTimer);
    timer->setInterval(1000);

    best_time = -1;
    time = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(tact()));
}



TSystem::~TSystem() {
    timer->stop();
    delete timer;
}



void TSystem::task_to_processor(int n) {
    if(tasks_queue.front() != nullptr) {
        processors[n - 1].set_current_task(tasks_queue.front());
        tasks_queue.move(0, tasks_queue.count() - 1);
        emit set_task_to_processor(n, processors[n - 1].current_task);
    }
    else {
        processors[n - 1].set_current_task(nullptr);
        tasks_queue.move(0, tasks_queue.count() - 1);
        processors[n - 1].active = 0;
        emit set_task_to_processor(n, nullptr);
    }
}



void TSystem::changeProcessorsNumber(int n) {
    if(!tasks_queue.isEmpty()){
        for(int i = processors.count(); i > 0; i--){
            tasks_queue.removeLast();
        }
    }

    for(int i = processors.count(); i > 0; i--){
        processors.removeLast();
    }

    for(int i = 0; i < n; i++){
        TProcessor proseccor = TProcessor(i + 1);
        processors.push_back(proseccor);
        tasks_queue.push_back(nullptr);
    }
    for(int i = 0; i < n; i++){
        connect(&processors[i], SIGNAL(task_request(int)), this, SLOT(task_to_processor(int)));
    }

    currentParam.curProcessorsNumber = n;
    time = 0;
    best_time = -1;

    emit show_current_processors(processors.count());
}



void TSystem::changeTasksNumber(int n) {
    if(!tasks.isEmpty()){
        for(int i = 0; i < currentParam.curTasksNumber; i++){
            tasks.removeLast();
        }
    }
    if(!tasks_queue.isEmpty()){
        for(int i = tasks_queue.count(); i > 0; i--){
            tasks_queue.pop_back();
        }
    }
    for(int i = 0; i < currentParam.curProcessorsNumber; i++){
        tasks_queue.push_back(nullptr);
    }
    for(int i = 0; i < n; i++){
        TTask task(i + 1, currentParam.minExecutionTime, currentParam.maxExecutionTime);
        tasks.append(task);
    }

    currentParam.curTasksNumber = n;
    time = 0;
    best_time = -1;

    emit show_current_tasks(tasks);
}



void TSystem::tact() {
    int inactive_processors = 0;
    for(int i = 0; i < processors.size(); i++){
        processors[i].tact();
        if(processors[i].active == 0){
            inactive_processors++;
        }
    }

    if(inactive_processors == processors.size()){
        if(best_time < 0 || best_time > time){
            best_time = time;
            emit new_record(best_time, tasks_queue);
        }

        for(int i = 0; i < tasks.count(); i++){
            tasks[i].current_time = 0;
        }

        time = 0;
        control(1);
        emit finished();
    }
    else{
        time++;
        emit current_time(time);
    }
}



void TSystem::add_to_queue(int n) {
    tasks_queue.insert(tasks_queue.count() - currentParam.curProcessorsNumber, &tasks[n - 1]);
}



void TSystem::add_to_list(int n) {
    tasks_queue.removeOne(&tasks[n - 1]);
}



void TSystem::control(int cmd) {
    if(cmd == 0){
        if(tasks.count() == 0){
            emit warning_signal(1);
            return;
        }
        if(tasks_queue.count() != tasks.count() + currentParam.curProcessorsNumber){
            emit warning_signal(0);
            return;
        }

        timer->start();
        for(int i = 0; i < currentParam.curProcessorsNumber; i++){
            (&processors[i])->active = 1;
        }
    }
    else{
        timer->stop();
        for(int i = 0; i < currentParam.curProcessorsNumber; i++){
            processors[i].active = 0;
        }
    }
}



void TSystem::reset() {
    currentParam = defaultParam;
    changeProcessorsNumber(currentParam.curProcessorsNumber);
    for(int i = tasks.count(); i > 0; i--){
        tasks.pop_back();
    }
    currentParam.curTasksNumber = 0;
}
