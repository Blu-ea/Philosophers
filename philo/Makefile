# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:03:53 by amiguez           #+#    #+#              #
#    Updated: 2022/09/29 17:09:05 by amiguez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
# **************************************************************************** #
LST_SRCS	:=	main.c\
				parsing.c\
				error.c\
				init.c\
				sim.c
LST_OBJS	:= $(LST_SRCS:.c=.o)
LST_INCS	:= philo.h
# **************************************************************************** #
DIR_SRC	:= new_srcs
DIR_OBJ	:= .objs
DIR_INC	:= includes
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
NORMINETTE = $(shell norminette $(SRCS) | grep -i 'Error:')
# **************************************************************************** #
# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra -g3 -fsanitize=thread

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

all: $(NAME)

$(NAME): $(OBJS) $(INCS) Makefile 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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

# \\\\\\\\\\\\\\\\\\\\\\\\\\ #

clean	:
	rm -rf $(DIR_OBJ)

fclean	:
	rm -rf $(DIR_OBJ)
	rm -rf $(NAME)

re : fclean all

.PHONY	: all clean fclean re $(LIBFT)
.SILENT	: