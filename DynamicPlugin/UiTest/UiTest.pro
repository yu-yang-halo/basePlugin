#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T09:36:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UiTest
TEMPLATE = app

win32 {
DESTDIR += ../Taiho_win
}
unix {
DESTDIR += ../Taiho_linux
}
UI_DIR += ./dist/forms
RCC_DIR += ./dist/tmp
MOC_DIR += ./dist/tmp
OBJECTS_DIR += ./dist/tmp

SOURCES += main.cpp\
        mainwindow.cpp \
    json/CJsonObject.cpp \
    json/cJSON.c \
    PluginsManager.cpp

HEADERS  += mainwindow.h \
    json/CJsonObject.hpp \
    json/cJSON.h \
    PluginsManager.h \
    interface/TaihoPluginInterface.h

FORMS    += mainwindow.ui
