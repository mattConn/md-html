\n {
    // close tags
    if(active)
    {
        if(h)
        {
            printf("</h%d>", h_num);
            h_num = 0;
            h = false;
        } else if(p) {
            printf("</p>");
            p = false;
        }
    }

    printf("%s", yytext);
}
