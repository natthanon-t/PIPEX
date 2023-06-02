# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:00:30 by ntairatt          #+#    #+#              #
#    Updated: 2023/06/02 18:32:37 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

#CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC)
CFLAGS = -I$(DIR_INC)

SRCS = pipex.c 

LIBFT = libft/libft.a

DIR_INC = include
DIR_SRC = src

RM = rm -f

#OBJS = $(addprefix $(DIR_SRC)/, $(SRCS:.c=.o))
OBJS = $(SRCS:.c=.o)

$(NAME): 
	@make bonus -C libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)


.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C libft
		@echo "object of pipex has removed"

fclean:
		@make fclean -C libft
		@$(RM) $(NAME)
		@echo "pipex has removed"

re: fclean all
