%{
    #include <iostream>
    #include <fstream>
    #include <cstring>
    extern std::fstream bison;
    extern "C" int yylex();
    extern "C" int yyparse();
    extern "C" FILE * yyin;
    extern int line_num;
    void yyerror(const char *s);
    
%}

%union {
    char *sval;
    int ival;
    char cval;
}

%token COMMA
%token SEMICOLON
%token OPEN_PARANTHESIS
%token CLOSE_PARANTHESIS
%token OPEN_SQUAREBRACKET
%token CLOSE_SQUAREBRACKET
%token OPEN_CURLYBRACE
%token CLOSE_CURLYBRACE
%token PLUSPLUS
%token PLUSEQUAL
%left PLUS MINUS
%token MINUSMINUS
%token MINUSEQUAL
%left MULTIPLY DIVIDE MODULO
%token NOT
%token NOTEQUAL
%token LESSEQUAL
%token LESSTHAN
%token GREATEREQUAL
%token GREATERTHAN
%token EQUAL
%token EQUALEQUAL
%token OR
%token AND
%token BOOLEAN
%token BREAK
%token CALLOUT
%token CLASS
%token CONTINUE
%token ELSE
%token FALSE
%token FOR
%token IF
%token INT
%token RETURN
%token TRUE
%token VOID
%token <sval> IDENTIFIER
%token <ival> INT_VALUE
%token <sval> STRING_VALUE
%token <cval> CHAR_VALUE

%type <sval> type
%type <sval> identifier_array

%%

program : CLASS IDENTIFIER OPEN_CURLYBRACE field_decl_list statement_decl_list CLOSE_CURLYBRACE { bison <<"PROGRAM ENCOUNTERED" << std::endl; }
        | CLASS IDENTIFIER OPEN_CURLYBRACE statement_decl_list CLOSE_CURLYBRACE { bison <<"PROGRAM ENCOUNTERED" << std::endl; }
        | CLASS IDENTIFIER OPEN_CURLYBRACE field_decl_list CLOSE_CURLYBRACE { bison <<"PROGRAM ENCOUNTERED" << std::endl; }
        | CLASS IDENTIFIER OPEN_CURLYBRACE CLOSE_CURLYBRACE { bison <<"PROGRAM ENCOUNTERED" << std::endl; }
        ;

field_decl_list : field_decl
                | field_decl_list field_decl
                ;

field_decl : type IDENTIFIER SEMICOLON { bison << $1 << " DECLARATION ENCOUNTERED. ID=" << $2 << std::endl; }
           | type identifier_array SEMICOLON { bison << $1 << " DECLARATION ENCOUNTERED. ID=" << $2 << std::endl; }
           ;

type : INT {{ $$ = strdup("INT"); }}
     | BOOLEAN {{ $$ = strdup("BOOLEAN"); }}
     ;

identifier_array : IDENTIFIER OPEN_SQUAREBRACKET INT_VALUE CLOSE_SQUAREBRACKET 
                   { 
                       char * scratch = (char *) malloc(sizeof(char) * (1 + strlen($1) + sizeof(" SIZE=") + 10));
                       char convertion_buffer[10];
                       sprintf(convertion_buffer, "%d", $3);
                       strcpy(scratch, $1);
                       strcat(scratch, " SIZE=");
                       strcat(scratch, convertion_buffer);
                       $$ = scratch;
                   }
                 ;

statement_decl_list : statement_decl
                    | statement_decl_list statement_decl
                    ; 

statement_decl : location assign_op expr SEMICOLON { bison << "ASSIGNMENT OPERATION ENCOUNTERED" << std::endl; }
               | CALLOUT OPEN_PARANTHESIS STRING_VALUE COMMA callout_arg_list CLOSE_PARANTHESIS SEMICOLON { bison << "CALLOUT TO " << $3 << " ENCOUNTERED" << std::endl; }
               | CALLOUT OPEN_PARANTHESIS STRING_VALUE CLOSE_PARANTHESIS SEMICOLON { bison << "CALLOUT TO " << $3 << " ENCOUNTERED" << std::endl; }
               ;

location : IDENTIFIER { bison << "LOCATION ENCOUNTERED=" << $1 << std::endl; }
         | IDENTIFIER OPEN_SQUAREBRACKET expr CLOSE_SQUAREBRACKET { bison << "LOCATION ENCOUNTERED=" << $1 << std::endl; }
         ;

assign_op : EQUAL 
          | PLUSEQUAL 
          | MINUSEQUAL 
          ;

expr : location
     | method_call
     | literal
     | expr PLUS expr { bison << "ADDITION ENCOUNTERED" << std::endl; }
     | expr MINUS expr { bison << "SUBTRACTION ENCOUNTERED" << std::endl; }
     | expr MULTIPLY expr { bison << "MULTIPLICATION ENCOUNTERED" << std::endl; }
     | expr DIVIDE expr { bison << "DIVISION ENCOUNTERED" << std::endl; }
     | expr MODULO expr { bison << "MOD ENCOUNTERED" << std::endl; }
     | expr rel_op expr
     | expr eq_op expr
     | expr cond_op expr
     | MINUS expr
     | NOT expr
     | OPEN_PARANTHESIS expr CLOSE_PARANTHESIS
     ;

method_call : method_name OPEN_PARANTHESIS expr_list CLOSE_PARANTHESIS
            | CALLOUT OPEN_PARANTHESIS STRING_VALUE COMMA callout_arg_list CLOSE_PARANTHESIS
            | CALLOUT OPEN_PARANTHESIS STRING_VALUE CLOSE_PARANTHESIS
            ;

method_name : IDENTIFIER
            ;

expr_list :
          | expr
          | expr_list COMMA expr
          ;

callout_arg_list : callout_arg
                 | callout_arg_list COMMA callout_arg
                 ;

callout_arg : expr 
            | STRING_VALUE
            ;

literal : int_literal
        | char_literal
        | bool_literal
        ;

int_literal : INT_VALUE { bison << "INT ENCOUNTERED=" << $1 << std::endl; }
            ;

char_literal : CHAR_VALUE { bison << "CHAR ENCOUNTERED=" << $1 << std::endl; }
             ;

bool_literal : TRUE { bison << "BOOLEAN ENCOUNTERED=true" << std::endl; }
             | FALSE { bison << "INT ENCOUNTERED=false" << std::endl; }
             ;

rel_op : LESSTHAN
       | GREATERTHAN
       | LESSEQUAL
       | GREATEREQUAL
       ;

eq_op : EQUALEQUAL
      | NOTEQUAL
      ;

cond_op : AND
        | OR
        ;
  
%%


void yyerror (const char *s) {
    std::cerr << "Parse error on line " << line_num << " ! Message : " << s << std::endl;
    exit(-1);
}

