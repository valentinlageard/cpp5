NAME		=	ex02
SRC			=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp

OBJS		=	$(SRC:.cpp=.o)

FLAGS		=	-Wall -Wextra -Werror -std=c++98
CC			=	clang++ $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CC) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:
			make clean
			rm -f $(NAME)
			rm -f **_shrubbery

re:			fclean all

.PHONY: 	all clean fclean re
