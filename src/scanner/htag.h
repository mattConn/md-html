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
