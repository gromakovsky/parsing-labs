.PHONY: all clean

all: obfuscation_parser.o obfuscation_scanner.o main.o obfuscator.o
	g++ -lboost_program_options *.o -o obfuscator

obfuscation_parser.cpp: obfuscation_parser.yy obfuscator.h
	bison --defines=obfuscation_parser.h -o obfuscation_parser.cpp obfuscation_parser.yy

.cpp.o:
	g++ -std=c++11 -c $< -o $@

obfuscation_scanner.cpp: obfuscation_scanner.ll obfuscation_parser.cpp obfuscator.h
	flex -o obfuscation_scanner.cpp obfuscation_scanner.ll 

clean:
	rm -f obfuscation_parser.{cpp,h} obfuscation_scanner.cpp *.o obfuscator *.hh
