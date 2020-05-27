EXEC = Cub3D

NAME = cub3d.a

MLX = libmlx_Linux.a

pars = pars/

l = libft/

FILES = main.c window.c manage_struct.c minimap.c what_user_do.c check_wall.c utils.c event.c print_view.c check_horiz_inter.c check_vert_inter.c print3d.c texture.c raycasting.c chain_list.c sprite.c free_struc.c screen.c pixel_bmp.c
FILESPARS = ${pars}parsing.c ${pars}for_parsing_map.c ${pars}for_parsing_text.c ${pars}dimension.c ${pars}check_void.c

FILESLIBFT = ${l}ft_itoa.c ${l}ft_putnbr_fd.c ${l}ft_strmapi.c ${l}ft_atoi.c ${l}ft_memccpy.c ${l}ft_putstr_fd.c ${l}ft_strncmp.c ${l}ft_bzero.c ${l}ft_memchr.c ${l}ft_split.c ${l}ft_strnstr.c ${l}ft_calloc.c ${l}ft_memcmp.c ${l}ft_strchr.c ${l}ft_strrchr.c ${l}ft_isalnum.c ${l}ft_memcpy.c ${l}ft_strdup.c ${l}ft_strtrim.c ${l}ft_isalpha.c ${l}ft_memmove.c ${l}ft_strjoin.c ${l}ft_substr.c ${l}ft_isascii.c ${l}ft_memset.c ${l}ft_strlcat.c ${l}ft_tolower.c ${l}ft_isdigit.c ${l}ft_putchar_fd.c ${l}ft_strlcpy.c ${l}ft_toupper.c ${l}ft_isprint.c ${l}ft_putendl_fd.c ${l}ft_strlen.c ${l}ft_utoa.c ${l}ft_strldup.c ${l}ft_ultoa_base.c ${l}ft_utoa_base.c ${l}get_next_line.c ${l}free_malloc_2d.c

OBJS = $(FILES:.c=.o)

OBJSLIBFT = $(FILESLIBFT:.c=.o)

OBJSPARS = $(FILESPARS:.c=.o)

.c.o : $(FILES)
	gcc -c -Wall -Wextra -Werror $(FILES)

$(NAME) : $(OBJS)
	make -C libft
	make -C pars
	ar rc $(NAME) $(OBJS) $(OBJSLIBFT) $(OBJSPARS)
	ranlib $(NAME)
	#gcc -o $(EXEC) main.o $(NAME) $(MLX)
	gcc -o $(EXEC) main.o $(NAME) -L/usr/local/include -lmlx -lm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lbsd



all : $(NAME)

compil : all
	gcc -o my.out $(NAME) main.c
	./my.out

clean :
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C pars

fclean : clean
	rm -rf $(NAME) $(EXEC)
	make fclean -C libft
	make clean -C pars

re : fclean all

.PHONY: all re clean fclean


