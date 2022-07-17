SRCS = $(wildcard *.c)
	  
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = cc

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS) 
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all
