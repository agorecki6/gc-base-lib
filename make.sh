gcc -o libgc-base -shared -std=c11 -I inc \
	-Wall -Wextra -Wpedantic -Werror \
	-D _IN_GC_BASE \
	src/comp.c
