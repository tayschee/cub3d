SRCS = for_parsing_map.c for_parsing_text.c parsing.c

OBJS = ${SRCS:.c=.o}

.c.o : ${SRCS}
	gcc -c -Wall -Wextra -Werror $<

all : ${OBJS}


clean :
	rm -f ${OBJS}
