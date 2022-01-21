SRCS	=	ft_fdf.c \


OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

MLXFLAG	=	-L minilibx-linux -lmlx -lXext -lX11

NAME = fdf


.c.o:
		${CC} ${CFLAGS} ${MLXFLAG} -I includes -c $< -o ${<:.c=.o}

all : ${CC} ${SRCS} ${CFLAGS} ${MLXFLAG}

${NAME} :	${CC} ${SRCS} ${CFLAGS} ${MLXFLAG}
			@echo "Relink ..."

clean :
		rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
