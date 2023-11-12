QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ../common

SOURCES += \
    application.cpp \
    main.cpp \
    interface.cpp \
    ../common/communicator.cpp \
    ../common/common.cpp

HEADERS += \
    application.h \
    interface.h \
    ../common/communicator.h \
    ../common/common.h
