void scanner(char *file_str)
{

	for(int i = 0; i < strlen(file_str); i++)
	{
		
		switch (file_str[i]) {

			#include "htag.h"			
			#include "htmltag.h"			
			#include "newline.h"			
			#include "codetag.h"			
			#include "lists-hr.h"			
			#include "emphasis-strong.h"			
			#include "backslash_escape.h"			

			//==============================
			// all characters, ptag
			//==============================

			//closed on newline (like htag)
			default:
				if(file_str[i-1] == '\n' && !in.code)
				{
					printf("<p>");
					in.p = true;
				}

				printf("%c", file_str[i]);
		}

	}	
}
