#-------------------------------------------------
#
# Project created by QtCreator 2017-05-30T21:09:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VehicleMonitor
    target.path = /home/pi/qt_devl

INSTALLS += target
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    applications/video/videocapture.cpp

HEADERS  += mainwindow.h \
    applications/video/videocapture.h \
    common.h

FORMS    += mainwindow.ui

INCLUDEPATH += /home/aziz/opencv_git/opencv/build_cross_comp/install/include
LIBS += -L/home/aziz/opencv_git/opencv/build_cross_comp/install/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_video \
    -lopencv_flann \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_imgcodecs \
    -lopencv_videoio
