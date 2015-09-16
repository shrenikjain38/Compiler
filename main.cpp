#include <iostream>
#include <cstdio>
#include <fstream>

extern "C" FILE *yyin; 
extern "C" int yyparse(); 
std::fstream flex;
std::fstream bison;
int main (const int argc, const char ** argv) {
    int success;
    if (argc < 2) {
        yyin = NULL;
        std::cerr <<"fatal error: no input files" << std::endl;
        return -1;
    } else {
        FILE *infile = fopen(argv[1], "r");
        if (!infile) {
            std::cerr <<"Error reading file " << argv[1] << std::endl;
            return -1;
        }
        yyin = infile;
    }
#ifdef DEBUG
    extern int yydebug;
    yydebug = 1;
#endif
    flex.open("flex_output.txt",std::fstream::out | std::fstream::trunc );
    bison.open("bison_output.txt",std::fstream::out | std::fstream::trunc );
    do {
         success = yyparse();
    } while (!feof(yyin));
    if(success == 0) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Syntax Error" << std::endl;
    }
    return 0;
}

