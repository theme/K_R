CC=clang
CFLAGS=-g

exetgts = e1-1+ e1-2+ e1-3+ e1-4+ \
		e1-5+ \
		e1-6+ \
		e1-7+ \
		e1-8+ \
		e1-15+ \
		funcOrder+ int+

tgts = e1-9replaceSpace	\
	   e1-10showEscape	\
	   e1-12	\
	   e1-13histogram	\
	   e1-14	\
	   e1-16longestline	\
	   e1-17	\
	   e1-19	\
	   e1-20detab	\
	   e1-21entab	\
	   e1-22fold	\
	   e1-23rmcom.c

$(tgts) :

$(exetgts) : %+: %
	./$<

.PHONY: $(exetgts) clean
clean:
		find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
		rm -f *.o *.d

