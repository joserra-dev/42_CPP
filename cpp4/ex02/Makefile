# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 11:43:24 by jllarena          #+#    #+#              #
#    Updated: 2025/02/03 14:18:45 by jllarena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP

NAME            = Abstract
CC              = c++
RM              = rm -rf
FLAGS           = -Wall -Wextra -Werror -std=c++98 -g3

#FILES AND PATH

HEADER_SRCS = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp\
HEADER_DIR  = includes/
HEADER      = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS  = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp\

MPATH_DIR   = mandatory/
MPATH       = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M       = $(MPATH:.cpp=.o)

#COMMANDS
all:        $(NAME)

$(NAME):    $(OBJ_M)
		    @$(CC) $(FLAGS) $(OBJ_M) -o $(NAME) 

%.o: %.cpp $(HEADER) Makefile
		    @$(CC) $(FLAGS) -c $< -o $@

clean:
	        @$(RM) $(OBJ_M)

fclean:	    clean
		    @$(RM) $(NAME)

re:         fclean all

.PHONY: all execute clean fclean re 