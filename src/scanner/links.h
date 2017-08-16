case '[':
if(!in.code)
{

int j = i, link_start = i, link_len = 0;
bool in_title = false; // inside title attr

// get length of link
while(file_str[j] != ')')
{
	j++;
	link_len++;

	//if not link, stop counting, break
	if(file_str[j] == '\n')
		break;
}

// reset index
j = i;

// advance index to url
while(file_str[j] != '(')
{
	j++;

	//if no closing link, stop searching
	if(file_str[j] == '\n')
	{
		printf("%c", file_str[i]);
		break;
	}
}

//print url
if(file_str[j] == '(')
{
	printf("<a href=\"");
	j++;

	while(file_str[j] != ')')
	{
		// print title attr
		if(file_str[j] == ' ' && file_str[j+1] == '\"')
		{
			printf("\" title=\"");
			j+=2;
			in_title = true;
		}

		printf("%c", file_str[j]);
		j++;
	}
}

// print anchor text
if(file_str[j] == ')')
{
	if(!in_title)
		printf("\"");

	printf(">");
	j = link_start + 1; // move back to beginning of link
	
	while(file_str[j] != ']')
	{
		printf("%c", file_str[j]);
		j++;
	}

	printf("</a>");
}

// skip over link
i += link_len;

}// end in.code check
break;
