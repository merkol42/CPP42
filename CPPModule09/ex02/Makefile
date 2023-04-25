NAME	:= PmergeMe
CC		:= c++
CFLAGS	:= -std=c++98 -Wall -Werror -Wextra
SRC_DIR	:= src/
OBJ_DIR	:= obj/
SRC		:= $(shell find $(SRC_DIR) -name "*.cpp")
OBJ		:= $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
INCLUDE	:= -I./include


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p obj

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ_DIR)

print:
	@echo $(SRC)