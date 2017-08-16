#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "line_state.h"
#include "copy_file.h"
#include "get_char_count.h"
#include "scanner/main.h"
#include "user_help_strings.h"
#include "argument_validation.h"

int main(int argc, char *argv[])
{
	if( !arg_validation(argc, argv[1]) )
		return 1;

	char file_str[ get_char_count(argv[1]) ];

	copy_file(argv[1], file_str);
	
	scanner(file_str);
	
	return 0;
}
