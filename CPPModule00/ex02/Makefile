NAME	:= banker
CC		:= g++
SRC_DIR	:= src
OBJ_DIR	:= obj
SRC		:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ		:= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCLUDE	:= -I./include
CFLAGS	:= -Wall -Werror -Wextra $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -pv $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ_DIR)

re: clean all

.PHONY: all clean fclean re