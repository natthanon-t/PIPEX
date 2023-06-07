# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:00:30 by ntairatt          #+#    #+#              #
#    Updated: 2023/06/06 21:01:09 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC	=	cc

#CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC) -I$(LIBFT_DIR)
CFLAGS	=	-I$(DIR_INC) -I$(LIBFT_DIR)

SRCS	=	pipex.c \
				child.c \
				check_path.c \
				check_error.c \
				ft_free.c


LIBFT	=	libft/libft.a

LIBFT_DIR = libft/include

DIR_INC	=	include
DIR_SRC	=	src

RM	=	rm -rf

$(NAME):
	@make bonus -C libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C libft
		@echo "Object files of Pipex has removed"

fclean: clean
		@$(RM) $(LIBFT)
		@$(RM) $(NAME)
		@echo "Libft has removed"
		@echo "Pipex has removed"

re: fclean all

norm:
	@echo "---------------- Libft -------------------"
	@make norm -C libft
	@echo "------------------------------------------\n"
	@echo "---------------- PIPEX -------------------"
	@norminette $(SRCS) $(DIR_INC)
	@echo "------------------------------------------\n"
