# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drohanne <drohanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:05:33 by drohanne          #+#    #+#              #
#    Updated: 2022/02/10 14:12:19 by drohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= megaphone.cpp
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs


OBJ_FILES	= $(SRC_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS 		= $(addprefix $(OBJS_DIR)/, $(OBJ_FILES))

NAME		= fdf
INCLUDE		= -I ./
DEPS		= $(OBJS:.o=.d)

CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD -MP #-march=native -O2

all:
			@${MAKE} $(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} $(INCLUDE) -o ${NAME}

$(LIBFT_A):	
			${MAKE} -C $(LIBFT_DIR)

-include $(DEPS)
$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
					@mkdir -p objs
					$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re