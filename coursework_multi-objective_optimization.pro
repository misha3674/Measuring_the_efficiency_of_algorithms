TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    load.c \
    tools/text_tools.c \
    draw.c \
    tools/text_area_tools.c \
    tools/texture_tools.c \
    proccessing.c \
    load_result.c \
    algorithm/l_a_genetic_algorithm.c \
    algorithm/l_a_particle_swarm.c \
    algorithm/l_a_simulatedannealing.c \
    algorithm/time_chrono.c \
    algorithm/commonalg.c \
    tools/button_tools.c \
    loadimage.c \
    tools/scale_tools.c

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
    tools/text_area_tools.h \
    tools/texture_tools.h \
    proccessing.h \
    load_result.h \
    algorithm/list2.h \
    algorithm/time_chrono.h \
    algorithm/commonalg.h \
    tools/button_tools.h \
    tools/scale_tools.h

DISTFILES += \
    bug.txt
