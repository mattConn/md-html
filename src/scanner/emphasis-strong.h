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
