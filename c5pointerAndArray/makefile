CC=clang
CFLAGS=-g

main:	main.c hello.c

shell: shell.cpp
	$(CC) $< -o $@
	./$@

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
