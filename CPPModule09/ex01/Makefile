NAME	:= RPN
CC		:= c++
CFLAGS	:= -std=c++98 -Wall -Werror -Wextra
OBJ_DIR	:= obj/
SRC		:= $(shell find -name "*.cpp")
OBJ		:= $(SRC:%.cpp=$(OBJ_DIR)%.o)
INCLUDE	:= -I.
INC_FILE:= RPN.hpp


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC_FILE)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p obj

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ_DIR)

print:
	@echo $(SRC)