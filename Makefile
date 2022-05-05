NAME = push_swap

SRCS = 	f_algorithm.c\
        f_algorithm2.c\
        f_algorithm3.c\
        f_operations_a.c\
        f_operations_b.c\
        f_operations_c.c\
        f_parse_args.c\
        f_sequence.c\
        f_split.c\
        f_utils_a.c\
        f_utils_b.c\
        f_utils_c.c\
        f_utils_libft_a.c\
        f_utils_libft_b.c\
        push_swap.c

OBJS =	$(SRCS:.c=.o)

INCLUDES = -I .

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(INCLUDES) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS) 
	$(CC) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re