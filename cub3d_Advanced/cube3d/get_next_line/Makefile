# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: forsili <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 16:07:41 by forsili           #+#    #+#              #
#    Updated: 2021/01/13 16:07:43 by forsili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

AR = ar -rc

RAN = ranlib

SRCS =	\
get_next_line.c \
get_next_line_utils.c 

OBJS = ${SRCS:.c=.o}


RM = rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}
	${RAN} ${NAME}


all: ${NAME}

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
