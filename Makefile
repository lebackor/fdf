SRCS	=	ft_fdf.c \


OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

NAME = fdf


.c.o:
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all : ${NAME}


$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
