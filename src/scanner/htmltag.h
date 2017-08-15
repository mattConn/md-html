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
