NAME = ex02
CC = c++ -std=c++98
CFLAGS =  -Wall -Wextra -Werror

SRC = main.cpp Base.cpp

all: $(NAME)

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp A.hpp B.hpp C.hpp Base.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all