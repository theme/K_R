CC=clang
CFLAGS=-g

tgts = goto+ 

$(tgts) : %+: %
	./$<

.PHONY: $(tgts) clean
clean:
		find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
		rm -f *.o *.d

