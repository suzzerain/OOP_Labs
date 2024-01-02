QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graph.cpp \
    interface.cpp \
    main.cpp \
    parsinggraph.cpp \
    sample.cpp \
    switcher.cpp

HEADERS += \
    graph.h \
    interface.h \
    parsinggraph.h \
    sample.h \
    switcher.h

DISTFILES += \
    inputGraph1.txt \
    inputGraph2.txt \
    inputGraph3.txt
