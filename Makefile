FILES = get_next_line \
		get_next_line_utils \
		test
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=1
INCLS = get_next_line.h
HEADERS = $(INCLS)
CFILES = $(addsuffix .c, $(FILES))
OFILES = $(addsuffix .o, $(FILES))
NAME = get_next_line
$(NAME): $(OFILES)
		$(CC) $(CFLAGS) -o $(NAME) $(OFILES)
%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@
all:	$(NAME)
clean:
		rm -f *.o
fclean:	clean
		rm -f $(NAME)
re:	fclean all
.PHONY: all clean fclean re