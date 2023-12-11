# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:17 by axdubois          #+#    #+#              #
#    Updated: 2023/12/11 09:54:11 by axdubois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fract-ol

LIB 	= libft.a

FLAG 	= -Wall -Wextra -Werror

SRC 	= Fract-ol.c Fract_hook.c ft_utils.c image.c
 
OBJS = $(SRC:.c=.o)

LIBFT  =    -lft -L./Libft 

all: $(NAME)

$(LIB):
	@make --quiet -C Libft re

$(NAME) : $(LIB) $(OBJS)
	@cc ${FLAG} $(OBJS) ${LIBFT} -Lmlx -lmlx_Linux -I./mlx -lXext -lX11 -lm -lz -o $@
 
clean :
	@rm -f $(OBJS)
	@make --quiet -C Libft clean
 
fclean : clean
	@rm -f $(NAME)
	@make  --quiet -C Libft fclean
 
re: fclean all

.SILENT:
	all
	
.PHONY: clean all re fclean 