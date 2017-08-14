// state of html tags (open, closed)
typedef struct {
	//bool h1, h2, h3, h4, h5, h6;
	bool h;
	bool p;
	bool ul, ol;
	bool code, codeblock;
	bool link;
} state;
state in;

// line status
typedef struct {
	bool newl;
	int h;
	int ccount;
	int code;
} LINE;
LINE line;
