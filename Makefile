NAME = get_next_line

SRCS = get_next_line.c get_next_line_utils.c

INCLUDE = get_next_line.h

OBJS = $(SRCS:%.c=%.o)

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c $(INCLUDE)
	gcc $(FLAGS) -o $@ $< -I

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $($NAME)

re: fclean all

.PHONY: all clean fclean re