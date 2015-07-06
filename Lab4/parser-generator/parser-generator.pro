TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += common

LIBS += -lboost_program_options

HEADERS += \
    common/errors.h \
    common/grammar.h \
    common/rule.h \
    common/token.h \
    grammar_reader/grammar_parser.h \
    grammar_reader/grammar_reader.h \
    common/translating_symbol.h \
    helper-files/parsing_context.h \
    parser-generating/generating.h

SOURCES += \
    grammar_reader/grammar_parser.cpp \
    grammar_reader/grammar_reader.cpp \
    grammar_reader/grammar_scanner.cpp \
    main.cpp \
    common/grammar.cpp \
    parser-generating/generating.cpp
