void scanner(char *file_str)
{

	for(int i = 0; i < strlen(file_str); i++)
	{
		
		switch (file_str[i]) {

			// count htag
            case '#':
                if(line.h < 6 && !in.code)
                    line.h++;
                else
                    printf("%c", file_str[i]);
                break;
			
			// open htag on space
			case ' ':

				if(line.h > 0 && !in.h && !in.code)
				{
					printf("<h%d>",line.h);
					in.h = true;
				} else {
					printf("%c", file_str[i]);
				}
				break;
			
			//html tag
			case '<':
				if(file_str[i+1] == '/')
					in.code = false;
				else
					in.code = true;	

				printf("%c", file_str[i]);
			break;

			//newline
			case '\n':
				// close htag if in htag
				if(in.h)
				{
					printf("</h%d>", line.h);
					in.h = false;
					line.h = 0;
				} else if(in.li) {
					//close li
					printf("</li>");
					in.li = false;

					if(file_str[i+1] != '-')
					{
						if(in.ul)
						{
							printf("\n</ul>");
							in.ul = false;
						} else {
							printf("\n</ol>");
							in.ol = false;
						}
					}
				} else if(in.p) {
					//close ptag if in ptag
					printf("</p>");
					in.p = false;
				}

				//print newline char
				printf("%c", file_str[i]);
				break;

			//code
			case '`':
				// if code block (3 backticks)
				if(file_str[i+1] == '`' && file_str[i+2] == '`')
				{
					//skip over next 2 backticks
					i+=2;
					if(!in.code)
					{
						printf("<pre><code>");
						in.code = true;
					} else {
						printf("</code></pre>");
						in.code = false;
					}
				// if inline code (1 backtick)
				} else if(!in.code) {
					printf("<code>");
					in.code = true;
				} else {
					printf("</code>");
					in.code = false;
				}
				break;
	
			// lists
			//unordered
			case '-':
				if(!in.code)
				{
					// on start of new line with space after dash, open ul
					if(file_str[i-1] == '\n' && file_str[i+1] == ' ' && !in.ul)
					{
						// skip over space
						i+=1;
	
						printf("<ul>\n");
						in.ul = true;

					//ordered
					} else if(file_str[i-1] == '\n' && file_str[i+1] == '.' && file_str[i+2] == ' ' && !in.ol) {
						// skip over period and space
						i+=2;
	
						printf("<ol>\n");
						in.ol = true;
					}

					printf("<li>");
					in.li = true;

				} else {
					printf("%c", file_str[i]);
				}
				break;

			default:
				if(file_str[i-1] == '\n' && !in.code)
				{
					printf("<p>");
					in.p = true;
				}

			printf("%c", file_str[i]);
		}

	}	
}
