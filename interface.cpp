#include "interface.h"



TProcessorsWindow::TProcessorsWindow(QWidget *parent) : QWidget(parent) {
    setMinimumWidth(250);

    QFont font;
    font.setPointSize(12);

    QPalette t;
    t.setColor(QPalette::Window,Qt::darkGreen);
    setAutoFillBackground(true);
    setPalette(t);

    t.setColor(QPalette::Window,Qt::darkGray);

    l = new QGridLayout(this);
    setLayout(l);

    header = new QLabel("Система", this);
    header->setFont(font);
    header->setAlignment(Qt::AlignCenter);
    header->setAutoFillBackground(true);
    header->setPalette(t);

    processors_widget_btn = new QPushButton("Работа процессоров", this);
    processors_widget_btn->setFont(font);
    processors_widget_btn->setAutoFillBackground(true);

    t.setColor(QPalette::Window, Qt::lightGray);
    processors_widget = new QWidget(this);
    processors_widget->hide();
    processors_widget->setAutoFillBackground(true);
    processors_widget->setPalette(t);

    vl = new QVBoxLayout(processors_widget);

    font.setPixelSize(32);
    t.setColor(QPalette::Window,Qt::darkGray);
    current_time_l = new QLabel("Текущее время: 0m. 0s.", processors_widget);
    current_time_l->setAutoFillBackground(true);
    current_time_l->setPalette(t);
    current_time_l->setFont(font);

    hl = new QHBoxLayout();

    vl->addWidget(current_time_l, 0, Qt::AlignCenter);
    vl->addLayout(hl);

    font.setPointSize(12);
    record_widget_btn = new QPushButton("Лучший результат", this);
    record_widget_btn->setFont(font);
    record_widget_btn->setAutoFillBackground(true);

    t.setColor(QPalette::Window, Qt::lightGray);
    record_widget = new QWidget(this);
    record_widget->hide();
    record_widget->setAutoFillBackground(true);
    record_widget->setPalette(t);

    record = new QWidget(record_widget);
    record->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    rl = new QGridLayout(record_widget);

    vlr = new QVBoxLayout(record);
    vlr->setAlignment(Qt::AlignTop);

    t.setColor(QPalette::Window, Qt::darkGray);
    record_scroll = new QScrollArea();
    record_scroll->setBackgroundRole(QPalette::Window);
    record_scroll->setFrameShadow(QFrame::Plain);
    record_scroll->setFrameShape(QFrame::NoFrame);
    record_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    record_scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    record_scroll->setWidgetResizable(true);
    record_scroll->setWidget(record);
    record_scroll->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    record_scroll->setMinimumHeight(575);
    record_scroll->setFixedWidth(350);
    record_scroll->setPalette(t);

    font.setPointSize(12);
    t.setColor(QPalette::Window, Qt::darkGray);

    record_queue_header = new QLabel ("Очередь заданий", record_widget);
    record_queue_header->setAlignment(Qt::AlignCenter);
    record_queue_header->setFont(font);
    record_queue_header->setAutoFillBackground(true);
    record_queue_header->setPalette(t);

    record_time_header = new QLabel ("Лучшее время: " + QString().setNum(0) + "m. " + QString().setNum(0) + "s.", record_widget);
    record_time_header->setAlignment(Qt::AlignCenter);
    record_time_header->setFont(font);
    record_time_header->setAutoFillBackground(true);
    record_time_header->setPalette(t);

    rl->addWidget(record_time_header, 0, 0, Qt::AlignCenter);
    rl->addWidget(record_queue_header, 1, 0, Qt::AlignCenter);
    rl->addWidget(record_scroll, 2, 0);

    l->setAlignment(Qt::AlignTop);
    l->setSpacing(0);
    l->addWidget(header, 0, 0, Qt::AlignTop);
    l->addWidget(processors_widget_btn, 1, 0, Qt::AlignTop);
    l->addWidget(processors_widget, 2, 0, Qt::AlignBottom);
    l->addWidget(record_widget_btn, 3, 0, Qt::AlignTop);
    l->addWidget(record_widget, 4, 0, Qt::AlignBottom);

    connect(processors_widget_btn, SIGNAL(pressed()), this, SLOT(show_processors_widget()));
    connect(record_widget_btn, SIGNAL(pressed()), this, SLOT(show_record_widget()));
}



TProcessorsWindow::~TProcessorsWindow() {
    delete header;
    delete processors_widget_btn;
    delete record_widget_btn;
    delete current_time_l;
    delete record_time_header;
    delete record_queue_header;
    delete vlr;
    delete rl;
    delete record;
    delete record_scroll;
    delete hl;
    delete vl;
    delete record_widget;
    delete processors_widget;
    delete l;
}



void TProcessorsWindow::show_processors_widget() {
    record_widget->hide();
    if (processors_widget->isHidden()) processors_widget->show();
    else processors_widget->hide();
}



void TProcessorsWindow::show_record_widget() {
    processors_widget->hide();
    if (record_widget->isHidden()) record_widget->show();
    else record_widget->hide();
}



void TProcessorsWindow::clear(int control) {
    current_time_l->setText("Текущее время: 0m. 0s.");
    for(int i = 0; i < processors.count(); i++){
        for(int j = processors[i]->completed_tasks_vl->count(); j > 0; j--){
            delete processors[i]->completed_tasks_vl->takeAt(0)->widget();
        }
    }
    if(control){
        record_time_header->setText("Лучшее время: 0m. 0s.");
        for(int i = 0; i < processors.count(); i++){
            for(int j = vlr->count(); j > 0; j--){
                delete vlr->takeAt(0)->widget();
            }
        }
    }
}



void TProcessorsWindow::show_processors(int n){
    if(!processors.empty()){
        for(int i = processors.count(); i > 0; i--){
            hl->removeWidget(processors.back());
            delete processors.back();
            processors.removeLast();
        }
    }
    for(int i = 0; i < n; i++){
        TProcessorView *processor = new TProcessorView(i);
        processors.push_back(processor);
        hl->addWidget(processors[i]);
    }
}



void TProcessorsWindow::show_current_time(int time){
    current_time_l->setText("Текущее время: " +
                  QString().setNum(time / 60) + "m. " +
                  QString().setNum(time % 60) + "s.");

    for(int i = processors.count() - 1; i >= 0; i--){
        if (processors[i]->current_task != nullptr){
            processors[i]->current_task->current_time_l->setText(QString().setNum(processors[i]->current_task->current_time_l->text().toInt() + 1));
        }
    }
}



void TProcessorsWindow::set_current_task(int n, TTask* task){
    processors[n - 1]->show_current(task);
}



void TProcessorsWindow::show_new_record(int best_time, QVector<TTask*> tasks_queue){
    record_time_header->setText("Лучшее время: " + QString().setNum(best_time / 60) +
                         "m. " + QString().setNum(best_time % 60) + "s.");
    for(int i = vlr->count(); i > 0; i--){
        delete vlr->takeAt(0)->widget();
    }
    for(int i = 0; i < tasks_queue.count(); i++){
        if(tasks_queue[i] != nullptr){
           vlr->addWidget(new TTaskRecordView(tasks_queue[i]->task_number, tasks_queue[i]->execution_time), 0, Qt::AlignCenter);
        }
    }
}




TControlWindow::TControlWindow(QWidget *parent) : QWidget(parent) {
    setFixedWidth(380);

    QFont font;
    font.setPointSize(13);

    QPalette t;
    t.setColor(QPalette::Window,Qt::darkGreen);
    setAutoFillBackground(true);
    setPalette(t);

    t.setColor(QPalette::Window,Qt::darkGray);
    header = new QLabel("Панель управления", this);
    header->setFont(font);
    header->setGeometry(15, 5, 350, 35);
    header->setAlignment(Qt::AlignCenter);
    header->setAutoFillBackground(true);
    header->setPalette(t);

    font.setPointSize(10);
    start_btn = new QPushButton("Начать", this);
    start_btn->setFont(font);
    start_btn->setGeometry(111, 45, 155, 40);

    reset_btn = new QPushButton("Сброс настроек", this);
    reset_btn->setFont(font);
    reset_btn->setGeometry(61, 45 + 45, 255, 40);
    reset_btn->setAutoFillBackground(true);
    reset_btn->setPalette(t);

    connect(start_btn, SIGNAL(pressed()), this, SLOT(start()));
    connect(reset_btn, SIGNAL(pressed()), this, SLOT(reset()));
}



TControlWindow::~TControlWindow() {
    delete header;
    delete start_btn;
    delete reset_btn;
}



void TControlWindow::block() {
    start_btn->setEnabled(!start_btn->isEnabled());
    reset_btn->setEnabled(!reset_btn->isEnabled());
}



void TControlWindow::start() {
    start_btn->setEnabled(false);
    reset_btn->setEnabled(false);
    emit start_signal(0);
}



void TControlWindow::reset(){
    emit reset_system(1);
}



TTasksWindow::TTasksWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(815, 1000);

    QFont font;
    font.setPointSize(12);

    QPalette t;
    t.setColor(QPalette::Window, Qt::darkGreen);
    setAutoFillBackground(true);
    setPalette(t);
    t.setColor(QPalette::Window, Qt::darkMagenta);

    l = new QGridLayout(this);

    tasks_list_header = new QLabel ("Задания", this);
    tasks_list_header->setAlignment(Qt::AlignCenter);
    tasks_list_header->setFont(font);
    tasks_list_header->setAutoFillBackground(true);
    tasks_list_header->setPalette(t);

    tasks_list_widget = new QWidget();
    tasks_list_widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    t.setColor(QPalette::Window, Qt::darkGray);
    tasks_list_scroll = new QScrollArea(this);
    tasks_list_scroll->setBackgroundRole(QPalette::Window);
    tasks_list_scroll->setFrameShadow(QFrame::Plain);
    tasks_list_scroll->setFrameShape(QFrame::NoFrame);
    tasks_list_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tasks_list_scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tasks_list_scroll->setWidgetResizable(true);
    tasks_list_scroll->setWidget(tasks_list_widget);
    tasks_list_scroll->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    tasks_list_scroll->setMinimumHeight(100);
    tasks_list_scroll->setPalette(t);
    tasks_list_scroll->setFixedWidth(370);

    t.setColor(QPalette::Window, Qt::darkMagenta);
    tasks_queue_header = new QLabel("Очередность заданий", this);
    tasks_queue_header->setAlignment(Qt::AlignCenter);
    tasks_queue_header->setFont(font);
    tasks_queue_header->setAutoFillBackground(true);
    tasks_queue_header->setPalette(t);

    tasks_queue_widget = new QWidget();
    tasks_queue_widget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    t.setColor(QPalette::Window, Qt::darkGray);
    tasks_queue_scroll = new QScrollArea(this);
    tasks_queue_scroll->setBackgroundRole(QPalette::Window);
    tasks_queue_scroll->setFrameShadow(QFrame::Plain);
    tasks_queue_scroll->setFrameShape(QFrame::NoFrame);
    tasks_queue_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tasks_queue_scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tasks_queue_scroll->setWidgetResizable(true);
    tasks_queue_scroll->setWidget(tasks_queue_widget);
    tasks_queue_scroll->setAlignment(Qt::AlignHCenter);
    tasks_queue_scroll->setMinimumHeight(100);
    tasks_queue_scroll->setPalette(t);
    tasks_queue_scroll->setFixedWidth(370);

    vll = new QVBoxLayout(tasks_list_widget);
    vll->setAlignment(Qt::AlignTop);

    vlq = new QVBoxLayout(tasks_queue_widget);
    vlq->setAlignment(Qt::AlignTop);

    l->setHorizontalSpacing(10);
    l->addWidget(tasks_list_header, 0, 0);
    l->addWidget(tasks_list_scroll, 1, 0);
    l->addWidget(tasks_queue_header, 0, 1);
    l->addWidget(tasks_queue_scroll, 1, 1);
}



TTasksWindow::~TTasksWindow() {
    for(int i = tasks.count() - 1; i >= 0; i--){
        delete tasks[i];
        tasks.pop_back();
    }
    delete vll;
    delete vlq;
    delete tasks_list_header;
    delete tasks_list_widget;
    delete tasks_list_scroll;
    delete tasks_queue_header;
    delete tasks_queue_widget;
    delete tasks_queue_scroll;
    delete l;
}



void TTasksWindow::show_current_tasks(QVector<TTask> tasks_list) {
    if(!tasks.empty()){
        for(int i = tasks.count(); i > 0; i--){
            vll->removeWidget(tasks.last());
            delete tasks.last();
            tasks.removeLast();
        }
    }
    int count = tasks_list.count();
    for(int i = 0; i < count; i++){
        TTaskView *task = new TTaskView(tasks_list[i].task_number, tasks_list[i].execution_time);
        tasks.append(task);
        vll->addWidget(task);
        connect(task, SIGNAL(reposition(TTaskView*)), this, SLOT(add_to_queue(TTaskView*)));
    }
}



void TTasksWindow::clear_tasks() {
    if(!tasks.empty()){
        for(int i = tasks.count(); i > 0; i--){
            vll->removeWidget(tasks.last());
            delete tasks.last();
            tasks.removeLast();
        }
    }
}



void TTasksWindow::add_to_queue(TTaskView* task) {
    vll->removeWidget(task);
    vlq->addWidget(task);
    task->move_btn->setText("Удалить\nиз очереди");
    disconnect(task, nullptr, nullptr, nullptr);
    connect(task, SIGNAL(reposition(TTaskView*)), this, SLOT(add_to_list(TTaskView*)));

    emit to_queue(tasks.indexOf(task) + 1);
}



void TTasksWindow::add_to_list(TTaskView* task) {
    vlq->removeWidget(task);
    int pos = 0;
    int index = tasks.indexOf(task);
    for(int i = 0; i < index; i++){
        if(vll->indexOf(tasks[i]) >= 0){
            pos++;
        }
    }
    vll->insertWidget(pos, task);

    task->move_btn->setText("Добавить\nв очередь");
    disconnect(task, nullptr, nullptr, nullptr);
    connect(task, SIGNAL(reposition(TTaskView*)), this, SLOT(add_to_queue(TTaskView*)));

    emit to_list(tasks.indexOf(task) + 1);
}



TSettingsWindow::TSettingsWindow(TSystemParam par, QWidget *parent) : QWidget(parent) {
    setFixedWidth(420);
    setMinimumHeight(165);

    QFont font;
    font.setPointSize(13);

    QPalette t;
    t.setColor(QPalette::Window, Qt::darkGreen);
    setAutoFillBackground(true);
    setPalette(t);

    t.setColor(QPalette::Window, Qt::darkGray);
    header = new QLabel("Параметры системы", this);
    header->setFont(font);
    header->setGeometry(10, 5, 400, 40);
    header->setAlignment(Qt::AlignCenter);
    header->setAutoFillBackground(true);
    header->setPalette(t);

    font.setPointSize(10);
    processors_number_l = new QLabel("Количество процессоров:", this);
    processors_number_l->setFont(font);
    processors_number_l->setGeometry(5, 65, 355, 40);
    processors_number_l->setAutoFillBackground(true);
    processors_number_l->setPalette(t);

    processors_number = new QSpinBox(this);
    processors_number->setFont(font);
    processors_number->setMinimum(par.minProcessorsNumber);
    processors_number->setMaximum(par.maxProcessorsNumber);
    processors_number->setValue(par.curProcessorsNumber);
    processors_number->setGeometry(365, 65, 50, 40);

    set_processors_number_btn = new QPushButton("Установить", this);
    set_processors_number_btn->setFont(font);
    set_processors_number_btn->setGeometry(5, 65 + 45, 355, 40);

    tasks_number_l = new QLabel("Количество заданий:", this);
    tasks_number_l->setAlignment(Qt::AlignCenter);
    tasks_number_l->setFont(font);
    tasks_number_l->setGeometry(5, 65 + 45 + 65, 355, 40);
    tasks_number_l->setAutoFillBackground(true);
    tasks_number_l->setPalette(t);

    tasks_number = new QSpinBox(this);
    tasks_number->setFont(font);
    tasks_number->setMinimum(par.minTasksNumber);
    tasks_number->setMaximum(par.maxTasksNumber);
    tasks_number->setValue(par.curTasksNumber);
    tasks_number->setGeometry(365, 65 + 45 + 65, 50, 40);

    generate_tasks_btn = new QPushButton("Создать", this);
    generate_tasks_btn->setFont(font);
    generate_tasks_btn->setGeometry(5, 65 + 45 + 65 + 45, 355, 40);

    connect(generate_tasks_btn, SIGNAL(pressed()), this, SLOT(generate_tasks()));
    connect(set_processors_number_btn, SIGNAL(pressed()), this, SLOT(set_processors_number()));
}



TSettingsWindow::~TSettingsWindow() {
    delete header;
    delete processors_number_l;
    delete processors_number;
    delete set_processors_number_btn;
    delete tasks_number_l;
    delete tasks_number;
    delete generate_tasks_btn;
}



void TSettingsWindow::generate_tasks() {
    emit generate(tasks_number->value());
}



void TSettingsWindow::set_processors_number() {
    emit set(processors_number->value());
}



void TSettingsWindow::block() {
    generate_tasks_btn->setEnabled(!generate_tasks_btn->isEnabled());
    set_processors_number_btn->setEnabled(!set_processors_number_btn->isEnabled());
}



TMainWindow::TMainWindow(TSystem *s, QWidget *parent) : QWidget(parent){
    system = s;
    TSystemParam par = s->getParam();

    pw = new TProcessorsWindow();
    sw = new TSettingsWindow(par);
    tw = new TTasksWindow();
    cw = new TControlWindow();

    l = new QGridLayout (this);
    l->addWidget(sw, 0, 0);
    l->addWidget(tw, 1, 0, 1, 2);
    l->addWidget(cw, 0, 1);
    l->addWidget(pw, 0, 2, 2, 1);

    connect(sw, SIGNAL(generate(int)), system, SLOT(changeTasksNumber(int)));
    connect(sw, SIGNAL(generate(int)), pw, SLOT(clear(int)));
    connect(system, SIGNAL(show_current_tasks(QVector<TTask>)), tw, SLOT(show_current_tasks(QVector<TTask>)));
    connect(sw, SIGNAL(set(int)), system, SLOT(changeProcessorsNumber(int)));
    connect(sw, SIGNAL(set(int)), pw, SLOT(clear(int)));
    connect(system, SIGNAL(show_current_processors(int)), pw, SLOT(show_processors(int)));

    connect(tw, SIGNAL(to_queue(int)), system, SLOT(add_to_queue(int)));
    connect(tw, SIGNAL(to_list(int)), system, SLOT(add_to_list(int)));
    connect(cw, SIGNAL(start_signal(int)), system, SLOT(control(int)));
    connect(cw, SIGNAL(start_signal(int)), pw, SLOT(clear(int))); 
    connect(cw, SIGNAL(start_signal(int)), sw, SLOT(block()));
    connect(cw, SIGNAL(start_signal(int)), pw, SLOT(clear(int)));

    connect(system, SIGNAL(warning_signal(int)), this, SLOT(warning(int)));
    connect(system, SIGNAL(warning_signal(int)), cw, SLOT(block()));
    connect(system, SIGNAL(warning_signal(int)), sw, SLOT(block()));

    connect(cw, SIGNAL(reset_system(int)), system, SLOT(reset()));
    connect(cw, SIGNAL(reset_system(int)), pw, SLOT(clear(int)));
    connect(cw, SIGNAL(reset_system(int)), tw, SLOT(clear_tasks()));

    connect(system, SIGNAL(finished()), this, SLOT(completed()));
    connect(system, SIGNAL(finished()), cw, SLOT(block()));
    connect(system, SIGNAL(finished()), sw, SLOT(block()));

    connect(system, SIGNAL(current_time(int)), pw, SLOT(show_current_time(int)));

    connect(system, SIGNAL(set_task_to_processor(int,TTask*)), pw, SLOT(set_current_task(int,TTask*)));

    connect(system, SIGNAL(new_record(int,QVector<TTask*>)), pw, SLOT(show_new_record(int,QVector<TTask*>)));

    tw->show_current_tasks(system->get_tasks());
    pw->show_processors(par.curProcessorsNumber);

    setWindowTitle("Распределение заданий на процессоры");
}



TMainWindow::~TMainWindow() {
    delete pw;
    delete sw;
    delete tw;
    delete cw;
    delete l;
}



void TMainWindow::warning(int warning_code) {
    if(warning_code == 0){
        QMessageBox::warning(this, "ERROR", "Не все задания добавлены в очередь!");
    }
    else if(warning_code == 1){
        QMessageBox::warning(this, "ERROR", "Нет сгенерированных заданий!");
    }
}



void TMainWindow::completed() {
    QMessageBox::information(this, "Отчет о завершении", "Система завершила работу!");
}

