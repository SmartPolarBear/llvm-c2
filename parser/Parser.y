
%{

#define BISONLEXFILE
#include "BisonFlexCommon.inc"
#undef BISONLEXFILE

extern "C" int yylex();
extern "C" int yyparse();

extern "C" FILE *yyin;

Block *root = nullptr;

void yyerror(const char *s);

%}

// token type definition
%union {
    int64_t token_value;

    std::string* string_value;
    int64_t integer_value;
    uint64_t uint_value;
    long double floating_value;

    ExpressionNode *expr;
    StatementNode *stmt;
    Block *block;
}

%token <string_value> TSTRING TIDENTIFIER
%token <integer_value>  TINTEGER
%token <floating_value> TDOUBLE
%token <uint_value> TUNSIGNED

%token <token_value> TCEQ TCNE TCLT TCLE TCGT TCGE TEQL
%token <token_value> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token <token_value> TPLUS TMINUS TMUL TDIV

%left TPLUS TMINUS
%left TMUL TDIV

%type <stmt> stmt var_decl
%type <ident> ident
%type <block> program stmts block

%start program

%% /* Grammar rules and actions follow */
program : stmts { root = $1; }
        ;
        
stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

stmt : var_decl | func_decl
     | expr { $$ = new NExpressionStatement(*$1); }
     ;

block : TLBRACE stmts TRBRACE { $$ = $2; }
      | TLBRACE TRBRACE { $$ = new NBlock(); }
      ;

var_decl : ident ident { $$ = new VariableDeclarationStatement($1, $2); }
         | ident ident TEQL expr { $$ = new VariableDeclarationStatement($1, $2, $4); }
         ;
        
func_decl : ident ident TLPAREN func_decl_args TRPAREN block 
            { $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
          ;
    
func_decl_args : /*blank*/  { $$ = new VariableList(); }
          | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
          | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
          ;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
      ;

numeric : TINTEGER { $$ = new IntegralExpression(atol($1->c_str())); delete $1; }
        | TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
        | TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
        ;
    
expr : ident TEQL expr { $$ = new NAssignment(*$<ident>1, *$3); }
     | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
     | ident { $<ident>$ = $1; }
     | numeric
     | expr comparison expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | TLPAREN expr TRPAREN { $$ = $2; }
     ;
    
call_args : /*blank*/  { $$ = new ExpressionList(); }
          | expr { $$ = new ExpressionList(); $$->push_back($1); }
          | call_args TCOMMA expr  { $1->push_back($3); }
          ;

comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE 
           | TPLUS | TMINUS | TMUL | TDIV
           ;
%%