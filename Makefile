CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c move.c sort.c utils.c more_utils.c
SRC	= $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
fclean: clean
	$(RM) $(NAME) $(OBJ_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR) 
re: fclean all

.PHONY: all clean fclean re
