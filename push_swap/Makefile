#AMES
NAME		= push_swap
MAKE		= make

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

#SRC
SRC_DIR		= src
SRC			= $(SRC_DIR)/push_swap.c \
			$(SRC_DIR)/parse.c \
			$(SRC_DIR)/parse_utils.c \
			$(SRC_DIR)/parse_utils_two.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/valid.c \
			$(SRC_DIR)/sort_mass.c \
			$(SRC_DIR)/put_push_in_list.c \
			$(SRC_DIR)/functions_a.c \
			$(SRC_DIR)/functions_b.c \
			$(SRC_DIR)/functions_duble.c \
			$(SRC_DIR)/sort_three.c \
			$(SRC_DIR)/sort_five.c \
			$(SRC_DIR)/sort_hund.c \
			$(SRC_DIR)/sort_three_ab.c \
			$(SRC_DIR)/sort_three_ab_two.c	


#INC
INC_DIR		= inc
INC			= $(INC_DIR) push_swap.h

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
