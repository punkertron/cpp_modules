NAME		=	btc
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -O2
SRCS		=	BitcoinExchange.cpp main.cpp
OBJS		=	${SRCS:.cpp=.o}
HEADER		=	BitcoinExchange.hpp
RM			=	rm -rf

${NAME}:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp ${HEADER}
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}