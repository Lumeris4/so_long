NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRCS = srcs/main.c srcs/so_long_utils.c srcs/errors.c srcs/positions.c srcs/shifting.c srcs/errors2.c srcs/errors3.c

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) -I. -I$(LIBFTDIR) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re