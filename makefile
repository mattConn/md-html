BIN = 'bin/mdhtml'
BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
COMPILER = 'clang'
FLAGS = '-Weverything'
TEST = 'test.md'

$(BIN): src/copy_file.h src/tag_states.h src/main.c
	$(BINCHECK) clang $(FLAGS) src/main.c -o $(BIN)

check:
	$(BIN) $(TEST)

clean:
	rm -rf bin 
