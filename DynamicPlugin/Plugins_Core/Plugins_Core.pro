#-------------------------------------------------
#
# Project created by QtCreator 2019-08-12T19:25:00
#
#-------------------------------------------------

QT       += core

TARGET = Plugins_Core
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
    interface/ITaihoServiceCore.h \
    impl/TaihoServiceCore.h

SOURCES += \
    json/CJsonObject.cpp \
    json/cJSON.c \
    impl/TaihoServiceCore.cpp

OTHER_FILES += Plugins_Core.json
