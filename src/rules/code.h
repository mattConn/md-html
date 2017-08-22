^"```" {
    // open/close code block    
    if(active)
    {
        printf("<pre><code>");
        active = false;
    } else {
        printf("</code></pre>");
        active = true;
    }
}

"`" {
	//open/close inline code tag
    if(active)
    {
        printf("<code>");
        active = false;
    } else {
        printf("</code>");
        active = true;
    }
}
