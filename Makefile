SRCS_C	= 	client.c
SRCS_S	= 	server.c
NAME_C	= client
NAME_S	= server
FLGS	= -Wall -Wextra -Werror
OBJS_C	= ${SRCS_C:.c=.o}
OBJS_S	= ${SRCS_S:.c=.o}
GCC		= gcc
RM		= rm -f


all:		printf ${NAME_C} ${NAME_S}

.c.o:	
			${GCC} ${FLGS} -c $< -o ${<:.c=.o}

${NAME_C}:	${OBJS_C}
			${GCC} ${FLGS} -I ./ft_printf/ -o ${NAME_C} ${OBJS_C} -L ./ft_printf/ -lftprintf
	
${NAME_S}:	${OBJS_S}
			${GCC} ${FLGS} -I ./ft_printf/ -o ${NAME_S} ${OBJS_S} -L ./ft_printf/ -lftprintf

printf:
			make -C ./ft_printf/

fclean:		clean
			make -C ./ft_printf/ fclean
			${RM} ${NAME} ${NAME_2}

clean:
			make -C ./ft_printf/ clean
			${RM} ${OBJS_C} ${OBJS_S}

re:			fclean all

.PHONY:		all fclean clean re