#include "widgets.h"



TProcessorView::TProcessorView(int n, QWidget *parent) : QWidget(parent) {
    QFont font;
    font.setPixelSize(25);

    QPalette p;
    p.setColor(QPalette::Window, QColor(255, 0, 0, 127));

    QPixmap *pic = new QPixmap("://resource//processor.png");

    processor_image = new QLabel(this);
    processor_image->setFixedSize(100, 100);
    processor_image->setPixmap(pic->scaled(100, 100));
    processor_image->setAutoFillBackground(true);
    processor_image->setPalette(p);

    processor_number_l = new QLabel("Процессор №" + QString().setNum(n + 1), this);
    processor_number_l->setFont(font);
    processor_number_l->setAutoFillBackground(true);
    processor_number_l->setPalette(p);

    vl = new QVBoxLayout(this);

    completed_tasks = new QWidget(this);
    completed_tasks_vl = new QVBoxLayout();
    completed_tasks->setLayout(completed_tasks_vl);
    completed_tasks_vl->setSpacing(20);

    scroll = new QScrollArea(this);
    scroll->setBackgroundRole(QPalette::Window);
    scroll->setFrameStyle(3);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setWidgetResizable(true);
    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { width: 15px; }");
    scroll->setMinimumHeight(500);
    scroll->setMinimumWidth(190);
    scroll->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);

    scroll->setWidget(completed_tasks);
    completed_tasks->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    vl->addWidget(scroll, 0, Qt::AlignRight);
    vl->addSpacing(20);
    vl->addWidget(processor_image, 0, Qt::AlignCenter);
    vl->addWidget(processor_number_l, 0, Qt::AlignCenter);
    vl->addSpacing(20);

    current_task = nullptr;

    vl->setAlignment(Qt::AlignHCenter);
    vl->addSpacing(76);
}



TProcessorView::~TProcessorView() {
    delete processor_image;
    delete processor_number_l;
    if(current_task != nullptr){
        delete current_task;
    }
    delete completed_tasks_vl;
    delete completed_tasks;
    delete scroll;
    delete vl;
}



void TProcessorView::show_current(TTask* task) {
    if(current_task != nullptr){
        vl->removeWidget(current_task);
        completed_tasks_vl->insertWidget(0, current_task);
    }
    else{
        vl->takeAt(vl->count() - 1);
    }
    if(task != nullptr){
        current_task = new TWorkTaskView(task->task_number, task->current_time, task->execution_time);
        vl->addWidget(current_task, 0, Qt::AlignCenter);
    }
    else{
        vl->addSpacing(76);
        current_task = nullptr;
    }
}



TWorkTaskView::TWorkTaskView(int n, int current_time, int time, QWidget *parent) : QWidget(parent) {
    QFont font;
    QPalette p;

    p.setColor(QPalette::Window, QColor(0, 0, 255, 127));
    setAutoFillBackground(true);
    setPalette(p);

    font.setPointSize(8);
    p.setColor(QPalette::Window, Qt::cyan);

    task_number_l = new QLabel("Задание " + QString().setNum(n), this);
    task_number_l->setFont(font);
    task_number_l->setAutoFillBackground(true);
    task_number_l->setPalette(p);

    time_l = new QLabel("Время: ", this);
    time_l->setFont(font);
    time_l->setAutoFillBackground(true);
    time_l->setPalette(p);

    current_time_l = new QLabel(QString().setNum(current_time), this);
    current_time_l->setFont(font);
    current_time_l->setAutoFillBackground(true);
    current_time_l->setPalette(p);

    execution_time_l = new QLabel("/" + QString().setNum(time) + "c.", this);
    execution_time_l->setFont(font);
    execution_time_l->setAutoFillBackground(true);
    execution_time_l->setPalette(p);

    l = new QGridLayout(this);
    l->setSpacing(0);

    l->addWidget(task_number_l, 0, 0, 1, 3, Qt::AlignCenter);
    l->addWidget(time_l, 1, 0, Qt::AlignBottom | Qt::AlignHCenter);
    l->addWidget(current_time_l, 1, 1, Qt::AlignBottom | Qt::AlignHCenter);
    l->addWidget(execution_time_l, 1, 2, Qt::AlignBottom | Qt::AlignHCenter);
    setFixedSize(155, 70);
}



TWorkTaskView::~TWorkTaskView() {
    delete execution_time_l;
    delete current_time_l;
    delete time_l;
    delete task_number_l;
    delete l;
}



TTaskView::TTaskView(int n, int time, QWidget *parent) : TTaskRecordView(n, time, parent) {
    QFont font;
    font.setPointSize(6);
    move_btn = new QPushButton("Добавить\nв очередь", this);
    move_btn->setFont(font);
    move_btn->setFixedSize(120, 60);
    connect(move_btn, SIGNAL(pressed()), this, SLOT(move_task()));

    l->addWidget(move_btn, 0, 2, 2, 1, Qt::AlignCenter);
}



TTaskView::~TTaskView() {
    delete move_btn;
}



void TTaskView::move_task() {
    emit reposition(this);
}



TTaskRecordView::TTaskRecordView(int n, int time, QWidget *parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    QFont font;
    font.setPointSize(10);

    QPalette p;
    p.setColor(QPalette::Window, QColor(0, 0, 255, 127));
    setAutoFillBackground(true);
    setPalette(p);

    p.setColor(QPalette::Window, Qt::cyan);

    task_number = new QLabel("Задание " + QString().setNum(n), this);
    task_number->setFont(font);
    task_number->setAutoFillBackground(true);
    task_number->setPalette(p);

    execution_time = new QLabel("Время: " + QString().setNum(time) + "c.", this);
    execution_time->setFont(font);
    execution_time->setAutoFillBackground(true);
    execution_time->setPalette(p);

    l = new QGridLayout(this);
    l->addWidget(task_number, 0, 1);
    l->addWidget(execution_time, 1, 1);
}



TTaskRecordView::~TTaskRecordView() {
    delete task_number;
    delete execution_time;
    delete l;
}
