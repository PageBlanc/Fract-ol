# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:17 by axdubois          #+#    #+#              #
#    Updated: 2026/05/24 10:29:47 by axdubois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fract-ol

LIB 	= libft.a

FLAG 	= -Wall -Wextra -Werror

BUILD_DIR = build

SRC 	= Fract-ol.c Fract_hook.c ft_utils.c image.c
 
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

LIBFT  = -lft -L./Libft 

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

all: $(NAME)

$(LIB):
	@make --quiet -C Libft/

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@cc ${FLAG} -c $< -o $@

$(NAME) : $(LIB) $(OBJS)
	@make --quiet -C mlx
	@cc ${FLAG} $(OBJS) ${LIBFT} -Lmlx -lmlx_Linux -I./mlx -lXext -lX11 -lm -lz -o $@
 
clean :
	@rm -rf $(BUILD_DIR)
	@make --quiet -C Libft/ clean
	@make --quiet -C mlx/ clean
 
fclean : clean
	@rm -f $(NAME)
	@make  --quiet -C Libft/ fclean
 
re: fclean all

.SILENT:
	all
	
.PHONY: clean all re fclean 