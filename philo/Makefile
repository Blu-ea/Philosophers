# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:03:53 by amiguez           #+#    #+#              #
#    Updated: 2022/05/23 19:30:24 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
# **************************************************************************** #
LST_SRCS	:= src.c etst.c test.c
LST_OBJS	:= $(SRC:.c=.o)
LST_INCS	:= phylo.h
LST_LIB		:= libft.a
# **************************************************************************** #
DIR_SRC	:= srcs
DIR_OBJ	:= .objs
DIR_INC	:= include
DIR_LIB	:= libft
# **************************************************************************** #
SRCS	:= $(addprefix "$(DIR_SRC)/", "$(LST_SRCS)")
OBJS	:= $(addprefix "$(DIR_OBJ)/", "$(LST_OBJS)")
INCS	:= $(addprefix "$(DIR_INC)/", "$(LST_INCS)")
LIBFT	:= $(addprefix "$(DIR_LIB)/", "$(LST_LIB)")
# **************************************************************************** #
ERASE	:=	\033[2K\r
GREY	:=	\033[30m
RED		:=	\033[31m
GREEN	:=	\033[32m
YELLOW	:=	\033[33m
BLUE	:=	\033[34m
PINK	:=	\033[35m
CYAN	:=	\033[36m
WHITE	:=	\033[37m
BOLD	:=	\033[1m
UNDER	:=	\033[4m
SUR		:=	\033[7m
END		:=	\033[0m
# **************************************************************************** #
# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS): $(SRCS) $(INCS) | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(LIBFT):
	make -C $(DIR_LIB)

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

clean	:
	rm -rf $(DIR_OBJ)
	make -C (DIR_LIB) clean

fclean	:
	rm -rf $(DIR_OBJ)
	rm -rf $(NAME)
	make -C (DIR_LIB) fclean

.PHONY	: all clean fclean
# .SILENT	: