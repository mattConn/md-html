int get_char_count(char *filename)
{
	FILE *file = fopen(filename, "r");

	char file_char = '\0';
	int count = 0;
	while(file_char != EOF )
	{
		file_char = fgetc(file);
		count++;
	}
	
	rewind(file);
	
	return count;
}
