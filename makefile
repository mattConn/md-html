BIN = 'bin/md-html'
BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
COMPILER = 'clang'
FLAGS = '-w'
TEST = 'test.md'

$(BIN): src/copy_file.h src/line_state.h src/main.c src/scanner/*
	$(BINCHECK) clang $(FLAGS) src/main.c -o $(BIN)

check:
	$(BIN) $(TEST)

clean:
	rm -rf bin 
