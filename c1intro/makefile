CC=clang
CFLAGS=-g

exetgts = e1-1+ e1-2+ e1-3+ e1-4+ \
		e1-5+ \
		e1-6+ \
		e1-7+ \
		e1-8+ \
		main+ histogram+ funcOrder+ int+

tgts = e1-9replaceSpace\
	   e1-10showEscape

$(tgts) : %: %

$(exetgts) : %+: %
	./$<

.PHONY: $(exetgts) clean
clean:
		find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
		rm -f *.o *.d

