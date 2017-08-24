^"###### " {
	//h-tags
	if(active)
	{
		printf("<h6>"); h = true; h_num = 6;
	} else {
		printf("%s", yytext);
	}
}
^"##### " {
	if(active)
	{
		printf("<h5>"); h = true; h_num = 5;
	} else {
		printf("%s", yytext);
	}
}

^"#### " {
	if(active)
	{
		printf("<h4>"); h = true; h_num = 4;
	} else {
		printf("%s", yytext);
	}
}
^"### " {
	if(active)
	{
		printf("<h3>"); h = true; h_num = 3;
	} else {
		printf("%s", yytext);
	}
}
^"## " {
	if(active)
	{
		printf("<h2>"); h = true; h_num = 2;
	} else {
		printf("%s", yytext);
	}
}
^"# " {
	if(active)
	{
		printf("<h1>"); h = true; h_num = 1;
	} else {
		printf("%s", yytext);
	}
}
