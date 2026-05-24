# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 15:25:03 by axdubois          #+#    #+#              #
#    Updated: 2026/05/24 10:02:05 by axdubois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

BUILD_DIR = build

SRCS    = 	 ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_bzero.c   \
			ft_isprint.c ft_memset.c  ft_strchr.c  ft_strlen.c  ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memcpy.c  \
			ft_memmove.c ft_memchr.c  ft_memcmp.c  ft_strlcat.c ft_strlcpy.c \
			ft_atoi.c    ft_calloc.c  ft_strdup.c  ft_substr.c  ft_strjoin.c \
			ft_split.c   ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c    \
			ft_putnbr_fd.c ft_itoa.c  ft_strtrim.c ft_strmapi.c ft_striteri.c\
			ft_printf.c  ft_printwrite.c ft_power.c

BSRCS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c 	 \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c   \
			ft_lstclear_bonus.c ft_lstiter_bonus.c    ft_lstmap_bonus.c

OBJS    = 	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

BOBJS	=	$(addprefix $(BUILD_DIR)/, $(BSRCS:.c=.o))

CC = cc

FLAGS = -Wall -Wextra -Werror 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

all : $(NAME) bonus

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean all re fclean bonus
