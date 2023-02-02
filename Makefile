# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 11:56:41 by jmaalouf          #+#    #+#              #
#    Updated: 2022/12/21 18:02:19 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# //= Variables =//

NAME	= fractol
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= $(LIBMLX)/glfw_lib/libglfw3.a $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -framework Cocoa -framework OpenGL -framework IOKit
SRCS	= src/main.c src/colors.c src/fractals.c src/hooks.c src/utils.c src/movement.c src/manipulation.c
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
GREEN	= \033[32;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@if [ -d ./lib/MLX42 ]; \
	then echo "\033[1;33m./lib/MLX42/ Exists\033[0m"; \
	else \
	git clone https://github.com/codam-coding-college/MLX42.git && \
	mv MLX42 ./lib && \
	curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip && \
	unzip glfw-3.3.8.bin.MACOS.zip && \
	rm glfw-3.3.8.bin.MACOS.zip && \
	mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib && \
	mv glfw-3.3.8.bin.MACOS/glfw_lib ./lib/MLX42/ && \
	rm -rf glfw-3.3.8.bin.MACOS; \
	fi
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
