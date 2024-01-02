#include "processor.h"


TProcessor::TProcessor() : QObject() {}

TProcessor::TProcessor(int number) : QObject() {
    active = 0;
    processor_number = number;
    current_task = nullptr;
}



TProcessor::TProcessor(const TProcessor& p) : QObject() {
    *this = p;
}



TProcessor& TProcessor::operator=(const TProcessor& p) {
    processor_number = p.processor_number;
    current_task = p.current_task;
    return *this;
}



void TProcessor::current_task_complete() {
    emit task_request(processor_number);
}



void TProcessor::tact() {
    if(active == 0){
        return;
    }

    if(current_task == nullptr || current_task->current_time == current_task->execution_time){
        current_task_complete();
        if (current_task != nullptr) current_task->current_time++;
    }
    else{
        current_task->current_time++;
    }
}



void TProcessor::set_current_task(TTask* task) {
    current_task = task;
}
