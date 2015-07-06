// test.cpp
#include <string>

int * q;
char ** d;
const std::string volatile * pointer; 

void run(char ** argv, char ** d, const char * s);

int main(int argc, char ** argv)
{
    run(argv, d, "aaa");
    return 0;
}
