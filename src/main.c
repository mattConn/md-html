#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "line_state.h"
#include "copy_file.h"
#include "get_char_count.h"
#include "scanner.h"

int main(int argc, char *argv[])
{
	char file_str[ get_char_count(argv[1]) ];

	copy_file(argv[1], file_str);
	
	scanner(file_str);
	
	return 0;
}
