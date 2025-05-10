NAME = ex01
CC = c++ -std=c++98
CFLAGS =  -Wall -Wextra -Werror

SRC = main.cpp Serializer.cpp

all: $(NAME)

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Serializer.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all