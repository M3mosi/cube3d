NAME	=	cub3D
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
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
			parse_rule4.c \
			print_error.c \
			print_error2.c \
			var_parsing.c \
			check_file.c \
			rendering.c \
			define_dir.c \
			spawn.c \
			raycasting.c \
			raycasting2.c \
			raycasting3.c \
			raycasting4.c \
			init.c \
			init2.c \
			sprite.c \
			sprite2.c \
			sprite3.c \
			print_map.c \
			sprite_mov.c \
			sprite_move2.c \
			sprite_move3.c \
			screenshot.c \
			floor.c \
			floor2.c \
			gun.c \
			gun2.c \
			gunprinter.c \
			gunprinter2.c \
			set_key.c \
			key_press.c \
			gameover.c \
			free.c

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

bonus	:	all

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			make clean -C ./libft

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft

re		:	fclean all

.PHONY	:	all bonus clean fclean re
