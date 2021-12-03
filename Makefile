SRCS_C	= 	client.c
SRCS_S	= 	server.c
NAME	= client
NAME_2	= server
FLGS	= -Wall -Wextra -Werror
OBJS_C	= ${SRCS_C:.c=.o}
OBJS_S	= ${SRCS_S:.c=.o}
GCC		= gcc
RM		= rm -f


all:		printf ${NAME}

.c.o:	
			${GCC} ${FLGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS_C} ${OBJS_S}
			${GCC} ${FLGS} -I ./ft_printf/ -o ${NAME} ${OBJS_C} -L ./ft_printf/ -lftprintf
			${GCC} ${FLGS} -I ./ft_printf/ -o ${NAME_2} ${OBJS_S} -L ./ft_printf/ -lftprintf

printf:		
			make -C ./ft_printf/

fclean:		clean
			${RM} ${NAME} ${NAME_2}

clean:
			${RM} ${OBJS_C} ${OBJS_S}

re:			fclean all

.PHONY:		all fclean clean re