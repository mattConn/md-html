void scanner(char *file_str)
{

	for(int i = 0; i < strlen(file_str); i++)
	{
		
		switch (file_str[i]) {

            case '#':
                if(line.h < 6 && !in.code)
                    line.h++;
                else
                    printf("%c", file_str[i]);
                break;
			
			case ' ':

				if(line.h > 0 && !in.h && !in.code)
				{
					printf("<h%d>",line.h);
					in.h = true;
				} else {
					printf("%c", file_str[i]);
				}
				break;

			case '\n':
				if(in.h)
				{
					printf("</h%d>", line.h);
					in.h = false;
					line.h = 0;
				}

				printf("%c", file_str[i]);
				break;

			case '`':
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
				} else if(!in.code) {
					printf("<code>");
					in.code = true;
				} else {
					printf("</code>");
					in.code = false;
				}
				break;

			default:
				printf("%c", file_str[i]);
		}

	}	
}
