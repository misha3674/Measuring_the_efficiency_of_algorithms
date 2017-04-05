TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    load.c \
    tools/text_tools.c

HEADERS += \
    load.h \
    common.h \
    tools/text_tools.h
