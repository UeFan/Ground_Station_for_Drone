#-------------------------------------------------
#
# Project created by QtCreator 2018-04-30T22:16:35
#
#-------------------------------------------------

QT       += core gui webenginewidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GroundStation_for_Drone
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp\
        server.cpp \
    bridge.cpp

HEADERS += \
        mainwindow.h \
        server.h \
    bridge.h

FORMS += \
        mainwindow.ui
INCLUDEPATH += /usr/local/include/opencv2/core \
                /usr/local/include/opencv \
                 -I /usr/include/python2.7
#INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13.2/include

LIBS            += /usr/local/lib/libopencv_highgui.so.3.4 \
                    /usr/local/lib/libopencv_core.so.3.4 \
                    /usr/local/lib/libopencv_videoio.so.3.4 \
                    /usr/local/lib/libopencv_imgproc.so.3.4 \
                    /usr/local/lib/libopencv_imgcodecs.so.3.4 \
                     -L /usr/lib/python2.7 -lpython2.7
#LIBS            += /usr/local/lib/libopencv_highgui.dylib \
#                    /usr/local/lib/libopencv_core.dylib \
#                     /usr/local/lib/libopencv_video.dylib

RESOURCES += \
    resources.qrc
# install
target.path = /Users/fanyue/Downloads/GroundStation_for_Drone
INSTALLS += target

DISTFILES += \
    bin/index.html
