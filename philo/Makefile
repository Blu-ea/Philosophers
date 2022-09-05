# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:03:53 by amiguez           #+#    #+#              #
#    Updated: 2022/09/05 15:34:11 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
# **************************************************************************** #
LST_SRCS	:=	main.c\
				pars.c\
				err.c\
				thread.c\
				time.c
LST_OBJS	:= $(LST_SRCS:.c=.o)
LST_INCS	:= philo.h
LST_LIB		:= libft.a
# **************************************************************************** #
DIR_SRC	:= srcs
DIR_OBJ	:= .objs
DIR_INC	:= includes
DIR_LIB	:= libft
# **************************************************************************** #
SRCS	:= $(addprefix $(DIR_SRC)/,$(LST_SRCS))
OBJS	:= $(addprefix $(DIR_OBJ)/,$(LST_OBJS))
INCS	:= $(addprefix $(DIR_INC)/,$(LST_INCS))
LIBFT	:= $(addprefix $(DIR_LIB)/,$(LST_LIB))
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
# **************************************************************************** #
NORMITEST = 
NORMINETTE = $(shell norminette $(SRCS) | grep -i 'Error')
# **************************************************************************** #
# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
THREAD_DR	:= -fsanitize=thread

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

all: $(NAME)

$(NAME): $(LIBFT) | $(OBJS) $(INCS) Makefile 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	printf "$(ERASE)$(WHITE)Compiling $(NAME) : $(GREEN) Done $(END)\n"

ifeq ($(NORMINETTE),$(NORMITEST))
	printf "$(GREEN)Everything is ok\n$(END)"
else
	printf "$(RED)$(SUR)THERE IS AN ERROR WITH NORMINETTE IN PHILO FILES !!$(END)\n"
endif

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INCS) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(ERASE)$(WHITE)Compiling $(NAME) : $(GREEN) $< $(END)$(ERROR)"

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(LIBFT):
	git submodule update --remote $(DIR_LIB)
	printf "$(YELLOW)\nLIBFT IS UP TO DATE!\n$(END)$(RED)"
	make -C $(DIR_LIB)

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

clean	:
	rm -rf $(DIR_OBJ)
	make -C $(DIR_LIB) clean

fclean	:
	rm -rf $(DIR_OBJ)
	rm -rf $(NAME)
	make -C $(DIR_LIB) fclean

re : fclean all

.PHONY	: all clean fclean re $(LIBFT)
# .SILENT	: