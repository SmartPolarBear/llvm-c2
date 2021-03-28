
%{

#define BISONLEXFILE
#include "BisonFlexCommon.inc"
#undef BISONLEXFILE

extern "C" FILE *yyin;

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
    VariableDeclarationStatement *var_decl;
    Block *block;
    IdentifierExpression *ident;

    FunctionDeclarationStatement::ArgListType *func_decl_args;
    FunctionCallingExpression::ArgListType *func_calling_args;
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

%type <ident> ident
%type <expr> numeric expr 
%type <func_decl_args> func_decl_args
%type <func_calling_args> call_args
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl
%type <token_value> comp

%start program

%% /* Grammar rules and actions follow */
program : stmts { Program::Instance().SetRoot($1); }
        ;
        
stmts : stmt { $$ = new Block(); $$->statements().push_back($<stmt>1); }
      | stmts stmt { $1->statements().push_back($<stmt>2); }
      ;

stmt : var_decl | func_decl
     | expr { $$ = new ExpressionStatement($1); }
     ;

block : TLBRACE stmts TRBRACE { $$ = $2; }
      | TLBRACE TRBRACE { $$ = new Block(); }
      ;

var_decl : ident ident { $$ = new VariableDeclarationStatement($1, $2); }
         | ident ident TEQL expr { $$ = new VariableDeclarationStatement($1, $2, $4); }
         ;
        
func_decl : ident ident TLPAREN func_decl_args TRPAREN block 
            { $$ = new FunctionDeclarationStatement($1, $2, $6,std::move(*$4)); delete $4; }
          ;
    
func_decl_args : /*blank*/  { $$ = new FunctionDeclarationStatement::ArgListType{}; }
          | var_decl { $$ = new FunctionDeclarationStatement::ArgListType{}; $$->push_back($<var_decl>1); }
          | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
          ;

ident : TIDENTIFIER { $$ = new IdentifierExpression(*$1); delete $1;}
      ;

numeric : TINTEGER { $$ = new IntegralExpression($1);}
        | TDOUBLE { $$ = new DoubleExpression($1);}
        | TUNSIGNED { $$ = new UnsignedExpression($1); }
        ;
    
expr : ident TEQL expr { $$ = new AssignmentExpression($<ident>1, $3); }
     | ident TLPAREN call_args TRPAREN { $$ = new FunctionCallingExpression($1, std::move(*$3));delete $3;}
     | ident { $<ident>$ = $1; }
     | numeric
     | expr comp expr { $$ = new BinaryOperatorExpression($1, $2, $3); }
     | TLPAREN expr TRPAREN { $$ = $2; }
     ;
    
call_args : /*blank*/ { $$ = new FunctionCallingExpression::ArgListType(); }
          | expr { $$ = new FunctionCallingExpression::ArgListType(); $$->push_back($1); }
          | call_args TCOMMA expr  { $1->push_back($3); }
          ;

comp : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE 
      | TPLUS | TMINUS | TMUL | TDIV
      ;

%%