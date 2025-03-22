NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
SRC = 	create_children.c	\
	exec_cmd.c		\
	setup_std_in_out.c	\
	pipex.c
SRC_DIR = src2/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
OBJ_DIR = obj2/

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

reclean:
	$(MAKE) re
	$(MAKE) clean

