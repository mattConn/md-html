BIN = 'bin/md-html'
BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
COMPILER = 'clang'
FLAGS = '-w'
TEST = 'test.md'

$(BIN): main.l lex.yy.c
	$(BINCHECK) $(COMPILER) $(FLAGS) lex.yy.c -lfl -o $(BIN); rm lex.yy.c; rm main.l;

lex.yy.c: main.l
	flex main.l

main.l: src/main.c
	lib/finc src/main.c > main.l

check:
	$(BIN) $(TEST)

clean:
	rm -r $(BIN); rm lex.yy.cl rm main.l;
