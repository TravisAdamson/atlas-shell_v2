CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = *.c
OBJ = $(SRC:%.c=%.o)
NAME = hsh
RM = rm

all: ${OBJ}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}
clean:
	${RM} -f *~ ${NAME}

oclean:
	${RM} -f ${OBJ}

fclean: clean oclean

re: oclean all
