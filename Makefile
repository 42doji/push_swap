SRCS = a_to_b.c b_to_a.c b_to_a2.c calc_cost.c command.c \
exception_check.c exception_check2.c exception_check3.c \
push_swap.c push_swap2.c push_swap3.c \
ft_split.c int_array.c pa_pb_sa_sb.c ra_rb_rra_rrb.c \
push_top_or_bottom.c stack.c three_data_sort.c utils.c \
print.c
OBJS = ${SRCS:.c=.o}
HEADER = push_swap.h
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re