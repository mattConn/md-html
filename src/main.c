%{

#include <stdio.h>
#include <stdbool.h>
#include "src/user_help_strings.h"
#include "src/argument_validation.h"

// tag states
bool h, p;
int h_num = 0;

bool active = true;

%}

%%

##include rules/h-tag.h
##include rules/p-tag.h
##include rules/code.h
##include rules/newline.h
##include rules/html.h

. { printf("%s", yytext); } //wildcard (everything else/all characters)

%%

int main(int argc, char *argv[])
{
	// check for valid argument
	if( !arg_validation(argc, argv[1]) )
		return 1;

	FILE *file;
	file = fopen(argv[1], "r");

	yyset_in(file);
	yylex();
	fclose(file);
}
