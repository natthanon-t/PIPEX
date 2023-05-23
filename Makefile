# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 08:35:29 by ntairatt          #+#    #+#              #
#    Updated: 2023/05/23 17:40:08 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC)

SRCS = 

LIBFT = libft/libft.a

DIR_INC = include
DIR_SRC = src

AR = ar -rcs

RM = rm -rf

#OBJS = $(addprefix $(DIR_SRC)/, $(SRCS:.c=.o))

$(NAME): 
	@make -C libft


.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C libft
		@echo "object of pipex has removed"


fclean:
		@make fclean -C libft
#@$(RM) $(NAME)
#@echo "pipex has removed"

re: fclean all

norm:
	@echo "Norminette is Checking......"
	@echo "-----------------------------------------------"
	@norminette $(addprefix $(DIR_SRC)/, $(SRCS))
	@echo "-----------------------------------------------"

