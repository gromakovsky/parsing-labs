.PHONY: all clean

all: grammar_parser.h grammar_parser.cpp grammar_scanner.cpp

grammar_parser.cpp: grammar_parser.yy grammar_reader.h
	bison --defines=grammar_parser.h -o grammar_parser.cpp grammar_parser.yy

grammar_parser.h: grammar_parser.cpp

grammar_scanner.cpp: grammar_scanner.ll
	flex -o grammar_scanner.cpp grammar_scanner.ll 

clean:
	rm -f grammar_parser.{cpp,h} grammar_scanner.cpp *.hh
