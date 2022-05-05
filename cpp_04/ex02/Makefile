SRC_FILES	=  main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.cpp=.o)

OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= program
DEPS		= $(OBJS:.o=.d)

RM			= rm -rf
CC			= c++
STANDART	= -std=c++98
CPPFLAGS	= -Wall -Wextra -Werror -MMD ${STANDART}

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CPPFLAGS} ${OBJS} -o ${NAME}

-include $(DEPS)
$(OBJS_DIR)/%.o :	%.cpp
					@mkdir -p objs
					$(CC) -c $(CPPFLAGS) $< -o $@

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re