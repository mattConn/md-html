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
