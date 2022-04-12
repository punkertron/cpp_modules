SRC_FILES	=  main.cpp
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.cpp=.o)

OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= file_program
DEPS		= $(OBJS:.o=.d)

CC			= c++
RM			= rm -rf
STANDART	= -std=c++98
CFLAGS		= -Wall -Wextra -Werror -MMD ${STANDART}

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

-include $(DEPS)
$(OBJS_DIR)/%.o :	%.cpp
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $< -o $@

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re