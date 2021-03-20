
%{
#include <cstdio>
#include <cstdint>

#include <iostream>
#include <string_view>

#include "types.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();

extern "C" FILE *yyin;

void yyerror(const char *s);

%}

// token type definition
%union {
    int64_t integer_value;
    raw_string string_value;
}

// constant tokens
%token PRINT
%token RUN
%token ENDL

// terminal symbols
%token <integer_value> LINE
%token <string_value> STRING

%% /* Grammar rules and actions follow */
input:
    /* empty */
    | input line
;
line:
    ENDL
    | stmt ENDL
;
stmt:
    LINE program        { cout << "> Programming line " << $1 << " ^^^" << endl; }
    | RUN            { cout << "> running..." << endl; }
;
program:
    PRINT STRING        { cout << ">\tPRINT " << $2 << endl; }
;
%%