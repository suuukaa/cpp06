NAME = ex00
CC = c++ -std=c++98
CFLAGS =  -Wall -Wextra -Werror

SRC = main.cpp ScalarConverter.cpp

all: $(NAME)

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all