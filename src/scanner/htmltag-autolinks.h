//==============================
//html tags, autolinks
//==============================

case '<':
{ //make expression for variable declarations in case

bool is_autolink = false;
int link_len = 0;
int j = i, link_start = i;
int times_link_printed = 0;

//check for autolink (dot will indicate link)
//===========================================
while(file_str[j] != '>' && file_str[j] != '.')
	j++;
if(file_str[j] == '.')
	is_autolink = true;
// reset link char index to beginning of link
j = i;

// print for autolink or print for html tag
//=========================================
if(is_autolink)
{
	if(!in.code){

	//get length of link
	do
	{
		j++;
		link_len++;
	}
	while(file_str[j] != '>');

	printf("<a href=\"");

	//print link twice; once for href, and again for text
	//===================================================
	while(times_link_printed < 2)
	{
		j = link_start+1;
		while(file_str[j] != '>')
		{
			printf("%c", file_str[j]);
			j++;
		}
		if(times_link_printed < 1)
			printf("\">");
		else
			printf("</a>");

		times_link_printed++;
	}
	
	//skip over link in file string
	i+=link_len+1;	
	
	}//end in.code check

} else { 
	// html tag
	//=========
	if(file_str[i+1] == '/')
		in.code = false;
	else
		in.code = true;
}
	printf("%c", file_str[i]);

}//end expression
	break;
