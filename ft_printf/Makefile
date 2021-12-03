SRCS	= 	ft_printf.c			\
			ft_printf_utils.c 	\
			ft_printf_utils_2.c

NAME	= libftprintf.a
FLGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
GCC		= gcc
RM		= rm -f
AR		= ar rc
RAN 	= ranlib

all:		${NAME}

.c.o:	
			${GCC} ${FLGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RAN} ${NAME}

fclean:		clean
			${RM} ${NAME}

clean:
			${RM} ${OBJS}

re:			fclean all

.PHONY:		all fclean clean re