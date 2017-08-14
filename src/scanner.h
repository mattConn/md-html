void scanner(char *file_str)
{
	line.ccount = 0;
	line.code = 0;

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
				if(line.h > 0 && !open.h && !open.code && !open.codeblock)
				{
					printf("<h%d>",line.h);
					open.h = true;
				} else {
					printf("%c", file_str[i]);
				}
				break;

			case '`':
				line.code++;
				if(line.code == 3)
				{
					if(!open.codeblock)
					{
						printf("<pre><code>");
						open.codeblock = true;
						line.code = 0;
					} else {
						printf("</code></pre>");
						open.codeblock = false;
						line.code = 0;
					}
				} else if(line.code == 2 && open.code) {
					printf("</code>");
					open.code = false;
					line.code = 0;
				}
				break;

			case '\n':
				// close h-tag if open
				if(open.h && !open.code && !open.codeblock)
				{
					printf("</h%d>",line.h);
					line.h = 0;
					open.h = false;

				} else if (open.p && !open.code && !open.codeblock) {

				// close p-tag if open
					printf("</p>");
					open.p = false;

				}
				printf("%c", file_str[i]);

				// reset line char count (indicates new line)
				line.ccount = 0;
				break;


			default:
				// open p-tag if beginning of line and not html tag
				if(line.ccount == 1 && file_str[i] != '<' && !open.code && !open.codeblock )
				{
					printf("<p>");
					open.p = true;
				}

				// open and close inline code tag
				if(line.code == 1 && !open.code) {
					printf("<code>");
					open.code = true;
				}

				printf("%c", file_str[i]);
		}

	}	
}
