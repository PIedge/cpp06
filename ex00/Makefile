SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

COM		=	c++

FLAG	=	-Wall -Wextra -Werror

NAME	=	convert

.cpp.o:
		$(COM) -c $(FLAG) $< -o $(<:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
			$(COM) $(FLAG) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
