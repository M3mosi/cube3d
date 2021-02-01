NAME	=	cub3d
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX		=	libmlx.dylib
SRCS	=	parsing.c \

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJ)
			make -C ./libft
			make -C ./get_next_line
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(LIBS)

$(MLX)	:
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

all		:	$(NAME)

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			make clean -C ./libft
			make clean -C ./get_next_line

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft
			make fclean -C ./get_next_line

re		:	fclean all

.PHONY	:	all clean fclean re
