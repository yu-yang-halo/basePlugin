#-------------------------------------------------
#
# Project created by QtCreator 2019-08-12T19:25:00
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plugins_AI
TEMPLATE = lib
CONFIG += plugin

win32 {
DESTDIR += ../Taiho_win/plugins
}
unix {
DESTDIR += ../Taiho_linux/plugins
}
UI_DIR += ./dist/forms
RCC_DIR += ./dist/tmp
MOC_DIR += ./dist/tmp
OBJECTS_DIR += ./dist/tmp

HEADERS += \
    json/CJsonObject.hpp \
    json/cJSON.h \
    interface/TaihoPluginInterface.h \
    impl/TaihoPluginAI.h \
    interface/ITaihoServiceCore.h \
    interface/IPlatformSystem.h

SOURCES += \
    json/CJsonObject.cpp \
    json/cJSON.c \
    impl/TaihoPluginAI.cpp

OTHER_FILES += Plugins_AI.json

FORMS += \
    impl/TaihoPluginAI.ui
