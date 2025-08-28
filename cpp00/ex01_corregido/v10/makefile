# Makefile simple para PhoneBook

NAME = phonebook
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = main.cpp phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = phonebook.hpp phonebook_utils.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
