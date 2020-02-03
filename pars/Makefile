FILES = for_parsing_text.c for_parsing_map.c parsing.c

OBJS = ${FILES:.c=.o}

all : ${FILES}
	gcc -c -Wall -Wextra -Werror $<

clean : ${OBJS}
	rm -f $<
