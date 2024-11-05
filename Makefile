
LIB_NAME=cmeth
CFLAGS=-Wall -g

test:
	deno run -A ./script/build.ts && gcc $(CFLAGS) ./tests/main.c -L ./include -l$(LIB_NAME) -o ./bin/test && ./bin/test
build:
	deno run -A ./script/build.ts






