NAME = ft_containers
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
OS = $(shell uname)
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 
# -fsanitize=address
STD = 0
GREEN = \033[32;1m
RED = \033[31;1m
UNDO_COL = \033[0m


SRC = 	$(SRC_DIR)main_vector.cpp 
# 		$(SRC_DIR)main_map.cpp \
		$(SRC_DIR)subject_main.cpp \
		$(SRC_DIR)main_vector.cpp \
		$(SRC_DIR)main_map.cpp \
		$(SRC_DIR)main_stack.cpp \


all: $(NAME)


$(NAME):
	@echo "$(RED)Compiling $(NAME)...$(UNDO_COL)"
	$(CC) $(CFLAGS) $(SRC) -D STD=1 -o std_containers
	$(CC) $(CFLAGS) $(SRC) -D STD=0 -o ft_containers
	@echo "$(GREEN)SUCCESSFULLY CREATED FT_CONTAINERS!$(UNDO_COL)"

clean:
	-rm -rf std_containers ft_containers iterator_overload std_containers.dSYM ft_containers.dSYM
	@echo "$(RED)Finished cleaning up$(UNDO_COL)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re