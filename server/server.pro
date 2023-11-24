QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../common

SOURCES += \
        application.cpp \
    complex.cpp \
        main.cpp \
        ../common/communicator.cpp \
        ../common/common.cpp \
    rational.cpp

HEADERS += \
    application.h \
    complex.h \
    double.h \
    matrix.h \
    rational.h \
    ../common/communicator.h \
    ../common/common.h \
    squarematrix.h
