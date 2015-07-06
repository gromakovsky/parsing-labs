TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cdecl_context.cpp \
    node.cpp \
    cdecl_lexical_iterator.cpp

HEADERS += \
    cdecl_parser.hpp \
    lexical_iterator.h \
    user_types.h \
    errors.h \
    cdecl_context.h \
    node.h \
    cdecl_lexical_iterator.h \
    node_fwd.h

