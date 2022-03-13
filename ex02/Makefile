SRCS	=	main.cpp		\

INC		= Classes/class_hpp/ABC.hpp

I_DIR_C	=	-Iincludes/ -IClasses/class_hpp

OBJS	=	$(SRCS:.cpp=.o)

COM		=	c++

FLAG	=	$(I_DIR_C) -Wall -Wextra -Werror

NAME	=	convert

.cpp.o:
		$(COM) -c $(FLAG) $< -o $(<:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS) $(INC)
			$(COM) $(FLAG) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
