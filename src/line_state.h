// state of html tags (open, closed)
typedef struct {
	bool h;
	bool p;
	bool ul, ol, li;
	bool em, strong;
	bool code;
	bool link;
} state;
state in;

// line status
typedef struct {
	int h;
} LINE;
LINE line;
