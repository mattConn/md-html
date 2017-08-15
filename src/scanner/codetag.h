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
