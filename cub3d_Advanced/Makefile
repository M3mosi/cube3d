NAME	=	cub3d
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	
RM		=	rm -f
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX		=	libmlx.dylib
SRCS	=	cub3d.c \
			get_next_line_utils.c \
			get_next_line.c \
			map_parsing.c \
			check_map.c \
			check_map2.c \
			parse_rule.c \
			parse_rule2.c \
			parse_rule3.c \
			print_error.c \
			var_parsing.c \
			check_file.c \
			rendering.c \
			define_dir.c \
			raycasting.c \
			init.c

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJ)
			make bonus -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(LIBS)

$(MLX)	:
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

all		:	$(NAME)

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			make clean -C ./libft

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re
