# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:02:17 by drohanne          #+#    #+#              #
#    Updated: 2022/02/13 13:52:48 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= megaphone.cpp
OBJS_DIR	= ./objs

OBJ_FILES	= $(SRC_FILES:.cpp=.o)

OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= megaphone
DEPS		= $(OBJS:.o=.d)

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD

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