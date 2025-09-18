NAME = clapTrap

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
RM = rm -f
SRC = main.cpp ClapTrap.cpp
OBJS = $(SRC .cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJ) - o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


