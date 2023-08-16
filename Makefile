NAME = GNL

SOURCE = get_next_line.c \
		  get_next_line_utils.c \

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = get_next_line.h

RM = rm -f

all: $(NAME)

run: $(NAME)
	./$(NAME) < teste.txt

$(NAME): $(OBJECTS) 
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
%.o:%.c $(INCLUDES)
		${CC} ${FLAGS} -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re