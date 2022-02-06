

CC := cc
CFLAGS := -c #-Wall -Wextra -Werror
SRCS :=	so_long.c so_long_util.c so_long_utils2.c
NAME := so_long
OBJS := ${SRCS:.c=.o}
	
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	gcc -Imlx -lmlx -framework OpenGl -framework Appkit $(OBJS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -D BUFFER_SIZE=1 libft/libft.a -g -o ${NAME}
clean : 
	$(MAKE) clean -C ./libft
	rm -f ${OBJS} 
fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus 