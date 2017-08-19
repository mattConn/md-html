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

^"###### " {
	//h-tags
	if(active)
	{
		printf("<h6>"); h = true; h_num = 6;
	} else {
		printf("%s", yytext);
	}
}
^"##### " {
	if(active)
	{
		printf("<h5>"); h = true; h_num = 5;
	} else {
		printf("%s", yytext);
	}
}

^"#### " {
	if(active)
	{
		printf("<h4>"); h = true; h_num = 4;
	} else {
		printf("%s", yytext);
	}
}
^"### " {
	if(active)
	{
		printf("<h3>"); h = true; h_num = 3;
	} else {
		printf("%s", yytext);
	}
}
^"## " {
	if(active)
	{
		printf("<h2>"); h = true; h_num = 2;
	} else {
		printf("%s", yytext);
	}
}
^"# " {
	if(active)
	{
		printf("<h1>"); h = true; h_num = 1;
	} else {
		printf("%s", yytext);
	}
}

"  "$ {
	//hard break p-tag
	if(active)
	{
		if(p)
		{
			printf("<br>");
		}
	}
}

^[a-zA-Z] { 
	// open p-tag
	if(active)
	{
		printf("<p>%s", yytext); p = true;
	} else {
		printf("%s", yytext);
	}
}

^"```" {
	// open/close code block	
	if(active)
	{
		printf("<pre><code>"); 
		active = false;
	} else {
		printf("</code></pre>"); 
		active = true;
	}
}

.$ {
	// close tags
	if(active)
	{
		if(h)
		{
			printf("</h%d>", h_num);
			h_num = 0;
			h = false;
		} else if(p) {
			printf("</p>");
			p = false;
		}
	}
	
	printf("%s", yytext);
}

. { printf("%s", yytext); }

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
