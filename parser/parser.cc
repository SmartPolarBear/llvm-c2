#include <iostream>

using namespace std;

void yyerror(const char *s){
    cout << "Error: " << s << endl;
}