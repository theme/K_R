CC=clang
CFLAGS=-g

tgt= math \
	 system \
	 string \
	 readf \
	 printf

$(tgt):

math: math.o
	$(CC) -lm $< -o $@
	rm $<

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
	find ./*.o -maxdepth 1 -type f -exec rm {} \;
