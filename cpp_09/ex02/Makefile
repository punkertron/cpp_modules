NAME		=	PmergeMe
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -O2
SRCS		=	main.cpp PmergeMe.cpp
OBJS		=	${SRCS:.cpp=.o}
INC			=	PmergeMe.hpp

RM			=	rm -rf

all:	${NAME}

${NAME}:	${OBJS} ${INC}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp ${INC}
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re