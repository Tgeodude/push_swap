#NAMES
NAME		= checker
MAKE		= make

#COMP USE CC INSTEAD?!?!??!
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

#SRC
SRC_DIR		= src
SRC			= $(SRC_DIR)/main.c \
			$(SRC_DIR)/functions_a.c \
			$(SRC_DIR)/functions_b.c \
			$(SRC_DIR)/functions_duble.c \
			$(SRC_DIR)/check_sort.c \
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/utils_2.c \
			$(SRC_DIR)/utils_3.c \

#INC
INC_DIR		= inc
INC			= $(INC_DIR) checker.h

#OBJ
OBJ_DIR		= obj
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

#OBJ_INC
OBJ_INC		= -I $(INC_DIR)

#RMS
RM_DIR		= rm -rf
RM_FILE		= rm -f

#DEPS
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

#OBJ DEPS
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(OBJ_INC) -c $< -o $@

$(OBJ)		:	| $(OBJ_DIR)
$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

#RULES
all:	$(NAME)

clean:
		${RM_DIR} ${OBJ_DIR}

fclean:	clean
		${RM_FILE} $(NAME)

re:		fclean all

#OTHER
.PHONY: all clean fclean re
