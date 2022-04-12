NAME = push_swap

SRCS = 	$(wildcard *.c)

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