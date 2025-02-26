NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
SRCS = get_path.c main.c new_process.c ft_free.c child_processes.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

reclean:
	$(MAKE) re
	$(MAKE) clean

