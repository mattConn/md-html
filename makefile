BIN = 'bin/md-html'
BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
COMPILER = 'clang'
FLAGS = '-w'
TEST = 'test.md'

$(BIN): src/main.l lex.yy.c
	$(BINCHECK) $(COMPILER) $(FLAGS) lex.yy.c -lfl -o $(BIN); rm lex.yy.c;

lex.yy.c: src/main.l
	flex src/main.l

check:
	$(BIN) $(TEST)

clean:
	rm $(BIN);
