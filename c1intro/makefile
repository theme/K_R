CC=clang
CFLAGS=-g

tgts = e1-1+ main+ histogram+ funcOrder+ int+

$(tgts) : %+: %
	./$<

.PHONY: $(tgts) clean
clean:
		find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
		rm -f *.o *.d

