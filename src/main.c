#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tag_states.h"
#include "copy_file.h"
#include "get_char_count.h"

int main(int argc, char *argv[])
{
	char file_str[ get_char_count(argv[1]) ];

	copy_file(argv[1], file_str);

	for(int i = 0; i<strlen(file_str); i++)
		printf("%c", file_str[i]);

	return 0;
}
