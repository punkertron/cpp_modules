# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:13:35 by drohanne          #+#    #+#              #
#    Updated: 2022/04/10 01:22:57 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= main.cpp Contact.cpp
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.cpp=.o)

OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= phonebook
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