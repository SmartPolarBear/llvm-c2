#include <iostream>
#include <string_view>

#include "Parser.h"
#include "Program.h"

using namespace std;

int main(int argc, char **argv)
{
	do
	{
		yyparse();
	} while (!feof(yyin));

	

	return 0;
}