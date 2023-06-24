# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:00:30 by ntairatt          #+#    #+#              #
#    Updated: 2023/06/24 23:53:13 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC	=	cc

CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC) -I$(LIBFT_DIR)

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
	@$(CC) $(CFLAGS) $(addprefix $(DIR_SRC)/, $(SRCS)) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@make clean -C libft
		@$(RM) $(NAME)
		@echo "Pipex has removed"

fclean: clean
		@$(RM) $(LIBFT)
		@echo "Libft has removed"

re: fclean all

norm:
	@make norm -C libft
	@echo "---------------- PIPEX -------------------"
	@norminette include src
	@echo "------------------------------------------\n"
