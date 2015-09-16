%{
    #include "dcc.tab.h"
    #define YY_DECL extern "C" int yylex()
    int line_num = 0;
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    extern std::fstream flex;
%}

%option noyywrap

DIGIT [0-9]
ALPHA [a-zA-Z]
UNDERSCOREDALPHA [a-zA-Z_]
HEXADECIMAL [0-9a-fA-F]
CHAR ([\40-\176]{-}['"\\])|\\n|\\t|\\\\|\\\"|\\\'

%%

\/\/.*\n {
    line_num++;
}

\, {
    return COMMA;
}

\; {
    return SEMICOLON;
}

\( {
    return OPEN_PARANTHESIS;
}

\) {
    return CLOSE_PARANTHESIS;
}

\[ {
    return OPEN_SQUAREBRACKET;
}

\] {
    return CLOSE_SQUAREBRACKET;
}

\{  {
    return OPEN_CURLYBRACE;
}

\}  {
    return CLOSE_CURLYBRACE;
}

\+\+ {
    return PLUSPLUS;
}

\+\= {
    return PLUSEQUAL;
}

\+ {
    return PLUS;
}

\-\- {
    return MINUSMINUS;
}

\-\= {
    return MINUSEQUAL;
}

\- {
    return MINUS;
}

\* {
    return MULTIPLY;
}

\/ {
    return DIVIDE;
}

\% {
    return MODULO;
}

\!\= {
    return NOTEQUAL;
}

\! {
    return NOT;
}

\<\= {
    return LESSEQUAL;
}

\< {
    return LESSTHAN;
}

\>\= {
    return GREATEREQUAL;
}

\> {
    return GREATERTHAN;
}

\=\= {
    return EQUALEQUAL;
}

\= {
    return EQUAL;
}

\|\| {
    return OR;
}

\&\& {
    return AND;
}

boolean {
    flex<<"BOOLEAN_DECLARATION\n";
    return BOOLEAN;
}

break {
    return BREAK;
}

callout {
    flex<<"CALLOUT\n";
    return CALLOUT;
}

class {
    flex<<"CLASS\n";
    return CLASS;
}

continue {
    return CONTINUE;
}

else {
    return ELSE;
}

false {
    flex<<"BOOLEAN: false\n";
    return FALSE;
}

for {
    return FOR;
}

if {
    return IF;
}

int {
    flex<<"INT_DECLARATION\n";
    return INT;
}

return {
    return RETURN;
}

true {
    flex<<"BOOLEAN: true\n";
    return TRUE;
}

void {
    return VOID;
}

{UNDERSCOREDALPHA}({UNDERSCOREDALPHA}|{DIGIT})* {
    yylval.sval = strdup(yytext);
    flex<<"ID: "<<yylval.sval<<"\n";
    return IDENTIFIER;
}

{DIGIT}+ {
    yylval.ival = atoi(yytext);
    flex<<"INT: "<<yylval.ival<<"\n";
    return INT_VALUE;
}

0x{HEXADECIMAL}+ {
    yylval.ival = atoi(yytext);
    return INT_VALUE;
}

\"{CHAR}*\" {
    yylval.sval = strdup(yytext);
    flex<<"STRING: "<<yylval.sval<<"\n";
    return STRING_VALUE;
}

\'{CHAR}\' {
    yylval.cval = yytext[1];
    flex<<"STRING: "<<yylval.cval<<"\n";
    return CHAR_VALUE;
}

[\t\ ] {
}

\n {
    line_num++;
}

. {
    std::cerr << "UNKNOWN SOMETHING HAS HAPPENED" << yytext;
}

%%
