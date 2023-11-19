# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 00:08:50 by lray              #+#    #+#              #
#    Updated: 2023/11/17 18:40:59 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= mlx-testing

SRCS		:= \
	./main.c \
	./img.c \
	./utils.c

OBJS		:= $(SRCS:.c=.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -I./inc
MLX			:= ./lib/libmlx.a -lXext -lX11

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(MLX) -o $(NAME)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

clean :
	$(RM) $(OBJS)
	$(info DELETED objects files)

fclean : clean
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re :
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY : clean fclean re info-
.SILENT :
