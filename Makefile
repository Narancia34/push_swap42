CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
NAME_B = checker

SRCS = get_next_line.c get_next_line_utils.c initialize_a.c initialize_b.c make_stack.c operations.c operations_2.c \
       parsing.c parsing_utils.c sort_3.c sort_stack.c utils_1.c utils_2.c push_swap.c \
       $(shell ls ./libft/*.c)
SRCS_B = get_next_line.c get_next_line_utils.c initialize_a.c initialize_b.c make_stack.c operations.c operations_2.c \
       parsing.c parsing_utils.c sort_3.c sort_stack.c utils_1.c utils_2.c checker.c \
       $(shell ls ./libft/*.c)

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
bonus: $(NAME_B)
$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
