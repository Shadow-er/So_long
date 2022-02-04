

CC := cc
CFLAGS := -g -Wall -Wextra -Werror
SRCS :=	ft_bzero.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c \
		ft_strchr.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_calloc.c \
		ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c \
		ft_strdup.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_isalnum.c \
		ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c
Bonus :=	ft_lstclear_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
			ft_lstnew_bonus.c ft_lstsize_bonus.c
NAME := libft.a
OBJS := ${SRCS:.c=.o}
OBJS_Bon := ${Bonus:.c=.o}
bon = bonus
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	ar rc $(NAME) $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)

$(bon): $(OBJS_Bon) $(OBJS)

clean : 
	rm -f ${OBJS} ${OBJS_Bon}
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re bonus 