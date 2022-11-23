NAME = ft_containers
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
OS = $(shell uname)
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address
STD = 0
GREEN = \033[0;32m
RED = \033[0;31m
UNDO_COL = \033[0m


SRC = 	$(SRC_DIR)main.cpp \
		$(SRC_DIR)utils.cpp \
		# $(SRC_DIR)subject_main.cpp \


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

debug: fclean dall

iterator_overload:
	@echo "$(RED)Compiling iterator_overload_test...$(UNDO_COL)"
	$(CC) $(CFLAGS) src/iterator_overload_test.cpp -o iterator_overload
	@echo "$(GREEN)SUCCESSFULLY CREATED iterator_overload_test!$(UNDO_COL)"

# dall: $(OBJ)
# 	@echo "$(RED)Compiling Debug 3 $(NAME)...$(UNDO_COL)"
# 	$(CC) $(CFLAGS) -D DEBUG=3 $^ -o $(NAME)
# 	@echo "$(GREEN)SUCCESSFULLY CREATED FT_CONTAINERS!$(UNDO_COL)"

# dspec: $(OBJ)
# 	@echo "$(RED)Compiling Debug 1 $(NAME)...$(UNDO_COL)"
# 	$(CC) $(CFLAGS) -D DEBUG=1 $^ -o $(NAME)
# 	@echo "$(GREEN)SUCCESSFULLY CREATED FT_CONTAINERS!$(UNDO_COL)"
 
.PHONY: all clean fclean re dall dspec debug