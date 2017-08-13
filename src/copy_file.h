void copy_file(char *filename, char *file_str)
{
	FILE *file = fopen(filename, "r");

	char file_char = '\0';
	int c = 0;

	while(file_char != EOF)
	{
		file_char = fgetc(file);

		file_str[c] = file_char;
		c++;
	}
	
	rewind(file);
}
