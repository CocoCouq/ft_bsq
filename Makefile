CC= gcc

CFLAGS= -Wall -Wextra -Werror

RM= /bin/rm -f

NAME= bsq

SRC= ./main.c \
	 ./_get_info.c \
	 ./_get_map.c \
	 ./_atoi.c \
	 ./_strlen.c \
	 ./_strjoin.c \
	 ./_solver.c \
	 ./_mallocstr.c \
	 ./_free.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
