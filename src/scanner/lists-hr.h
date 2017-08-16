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
