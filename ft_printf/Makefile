NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

AR = ar rc

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
