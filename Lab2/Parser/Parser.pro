TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lexical_iterator.cpp \
    parser.cpp \
    node.cpp

HEADERS += \
    lexical_iterator.h \
    parser.h \
    node.h

