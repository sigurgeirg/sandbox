TEMPLATE = app
TARGET = messages
CONFIG += console
CONFIG -= qt

LIBS += -lmosquittopp

HEADERS += \
    inc/ClientSub.h \
    inc/BrokerPub.h
SOURCES += src/main.cpp \
    src/ClientSub.cpp \
    src/BrokerPub.cpp

CONFIG(release, debug|release) {
        DESTDIR = release
} else {
        DESTDIR = debug
}
