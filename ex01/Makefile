# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 21:00:39 by seozkan           #+#    #+#              #
#    Updated: 2023/06/09 21:00:55 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fixed
CC			= g++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS_DIR 	= src
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

INCS_DIR	= inc
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

MAIN_INC	= -I$(INCS_DIR)

CYAN 		= \033[1;36m
END			= \033[0m
CLEAR    	= \033[2K

.cpp.o:
	@printf "$(CLEAR)$(CYAN)Compiling: $<$(END)\r"
	@ ${CC} ${CFLAGS} ${MAIN_INC} -c $< -o ${<:.cpp=.o}

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "\n${NAME} compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re