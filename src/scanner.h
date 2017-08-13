void scanner(char *file_str)
{
	line.ccount = 0;

	for(int i = 0; i < strlen(file_str); i++)
	{
		line.ccount++;
		switch (file_str[i]) {
			case '#':
				// count #'s for h-tag
				if(line.h < 6 && !open.h && !open.code && !open.codeblock)
					line.h++;
				else
					printf("%c", file_str[i]);

				break;
			
			case ' ':
				// open h-tag
				if(line.h > 0 && !open.h)
				{
					printf("<h%d>",line.h);
					open.h = true;
				} else {
					printf("%c", file_str[i]);
				}
				break;

			case '\n':
				// close h-tag if open
				if(open.h)
				{
					printf("</h%d>",line.h);
					line.h = 0;
					open.h = false;
				} else if (open.p) {
					printf("</p>");
					open.p = false;
				}

				printf("%c", file_str[i]);
				// reset line char count (indicates new line)
				line.ccount = 0;
				break;

			default:
				if(line.ccount == 1)
				{
					printf("<p>");
					open.p = true;
				}
				printf("%c", file_str[i]);
		}

	}	
}
