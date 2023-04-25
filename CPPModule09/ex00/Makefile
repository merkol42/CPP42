NAME	:= btc
CC		:= c++
CFLAGS	:= -std=c++98 -Wall -Werror -Wextra
SRC_DIR	:= src/
OBJ_DIR	:= obj/
SRC		:= $(shell find $(SRC_DIR) -name "*.cpp")
OBJ		:= $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
INCLUDE	:= -I./include
INC_FILE:= ./include/BitcoinExchange.hpp


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC_FILE)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p obj

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ_DIR)

print:
	@echo $(SRC)