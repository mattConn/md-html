^[a-zA-Z] {
    // open p-tag
    if(active)
    {
        printf("<p>%s", yytext); p = true;
    } else {
        printf("%s", yytext);
    }
}
