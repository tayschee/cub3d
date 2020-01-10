NAME = cub3d.a

EXEC = Cub3D

l = ./libft/

SRCS = start.c map_is_ok?.c

SRCSLIBFT = ${l}ft_itoa.c ${l}ft_putnbr_fd.c ${l}ft_strmapi.c ${l}ft_atoi.c ${l}ft_memccpy.c ${l}ft_putstr_fd.c ${l}ft_strncmp.c ${l}ft_bzero.c ${l}ft_memchr.c ${l}ft_split.c ${l}ft_strnstr.c ${l}ft_calloc.c ${l}ft_memcmp.c ${l}ft_strchr.c ${l}ft_strrchr.c ${l}ft_isalnum.c ${l}ft_memcpy.c ${l}ft_strdup.c ${l}ft_strtrim.c ${l}ft_isalpha.c ${l}ft_memmove.c ${l}ft_strjoin.c ${l}ft_substr.c ${l}ft_isascii.c ${l}ft_memset.c ${l}ft_strlcat.c ${l}ft_tolower.c ${l}ft_isdigit.c ${l}ft_putchar_fd.c ${l}ft_strlcpy.c ${l}ft_toupper.c ${l}ft_isprint.c ${l}ft_putendl_fd.c ${l}ft_strlen.c ${l}ft_utoa.c ${l}ft_strldup.c ${l}ft_ultoa_base.c ${l}ft_utoa_base.c ${l}get_next_line.c

OBJS = ${SRCS:.c=.o}
OBJSLIBFT = ${SRCSLIBFT:.c=.o}

.c.o : ${SRCS}
	gcc -c -Wall -Wextra -Werror $<

3D.a: ${OBJS}
	make -C libft
	ar rc ${NAME} ${OBJSLIBFT} ${OBJS}
	ranlib ${NAME}

all : 3D.a

clean : 
	make clean -C libft
	rm -f ${OBJS}

fclean:
	make fclean -C libft
	rm -f ${NAME}

re : fclean all

compil : all
	gcc -o ${EXEC} start.o ${NAME}




