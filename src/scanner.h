void scanner(char *file_str)
{

	for(int i = 0; i < strlen(file_str); i++)
	{
		
		switch (file_str[i]) {

			//==============================
			// count htag
			//==============================
            case '#':
                if(line.h < 6 && !in.code)
                    line.h++;
                else
                    printf("%c", file_str[i]);
                break;
			
			//==============================
			// open htag on space
			//==============================
			case ' ':

				if(line.h > 0 && !in.h && !in.code)
				{
					printf("<h%d>",line.h);
					in.h = true;
				} else {
					printf("%c", file_str[i]);
				}
				break;
			
			//==============================
			//html tag
			//==============================
			case '<':
				if(file_str[i+1] == '/')
					in.code = false;
				else
					in.code = true;	

				printf("%c", file_str[i]);
			break;

			//==============================
			//newline
			//==============================
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

			//==============================
			//code tag
			//==============================
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
	
			//==============================
			// lists and horizontal rule
			//==============================

			//---------------------
			//unordered
			//---------------------
			case '-':
				if(!in.code)
				{
					//---------------------
					//horizontal rule
					//---------------------
					if(file_str[i-1] == '\n' && file_str[i+1] == '-' && file_str[i+2] == '-')
					{
						//skip over 2 dashes
						i+=2;
						printf("<hr>");
						break;
					}

					// on start of new line with space after dash, open ul
					if(file_str[i-1] == '\n' && file_str[i+1] == ' ' && !in.ul)
					{
						printf("<ul>\n");
						in.ul = true;
					
					//---------------------
					//ordered
					//---------------------
					} else if(file_str[i-1] == '\n' && file_str[i+1] == '.' && file_str[i+2] == ' ' && !in.ol) {
						printf("<ol>\n");
						in.ol = true;
					}

					//num. of characters to skip for each list type
					if(in.ol)
						i+=2;
					else
						i++;

					printf("<li>");
					in.li = true;

				} else {
					printf("%c", file_str[i]);
				}
				break;

			//==============================
			//emphasis, strong
			//==============================
			case '*':
				if(!in.code)
				{
					if(file_str[i+1] == '*')
					{
						i++;
						if(!in.strong)
						{
							printf("<strong>");
							in.strong = true;
						} else {
							printf("</strong>");
							in.strong = false;
						}
					} else {
						if(!in.em)
						{
							printf("<em>");
							in.em = true;
						} else {
							printf("</em>");
							in.em = false;
						}
					}
				}
				break;

			//==============================
			// backslash escape
			//==============================
			case '\\':
				i++;
				printf("%c", file_str[i]);
				break;

			//==============================
			// all characters, ptag
			//==============================
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
