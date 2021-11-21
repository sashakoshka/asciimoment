all:
	clang -Wall -Wextra -Werror -Wpedantic main.c -o bin/ascmt

clean:
	rm -f bin/*

run: all
	./bin/ascmt

install:
	install bin/ascmt /usr/local/bin/ascmt

uninstall:
	rm -f /usr/local/bin/ascmt
