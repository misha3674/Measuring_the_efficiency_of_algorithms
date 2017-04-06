TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    load.c \
    tools/text_tools.c \
    draw.c \
    tools/text_area_tools.c

QMAKE_CFLAGS += -std=c11

QT   += opengl
LIBS += -lopengl32

win32: LIBS += -L$$PWD/glfw/lib/ -lglfw3 -lgdi32
win32: LIBS += -L$$PWD/glut/lib/ -lglut32
win32: LIBS += -L$$PWD/freeimage -lFreeImage

HEADERS += \
    load.h \
    common.h \
    tools/text_tools.h \
    draw.h \
    loadimage.h \
    freeimage/FreeImage.h \
    glfw/include/glfw3.h \
    glfw/include/glfw3native.h \
    glut/include/glut.h \
    tools/text_area_tools.h
