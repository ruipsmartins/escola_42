NAME	=	Form

CPP		=	c++

SRCS	=	main.cpp Bureaucrat.cpp Form.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS=	-Wall -Werror -Wextra -std=c++98 -I./

RM		=	rm -rf

all	:		$(NAME)

$(NAME) :	$(OBJS)
			@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			@$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:			
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

r:			re
			@valgrind ./$(NAME)
