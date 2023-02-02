# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:02:48 by jmaalouf          #+#    #+#              #
#    Updated: 2022/10/11 08:23:51 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_atof.c ft_strncmp.c ft_isnum.c

SRC_OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${SRC_OBJ}
	ar rcs $@ $^

${SRC_OBJ}:
	${CC} ${FLAGS} -c ${SRC}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re