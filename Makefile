# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:00:30 by ntairatt          #+#    #+#              #
#    Updated: 2023/06/04 12:31:39 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC	=	cc

#CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC)
CFLAGS	=	-I$(DIR_INC)

SRCS	=	pipex.c \
				child.c \
				check_path.c \
				ft_free.c

LIBFT	=	libft/libft.a

DIR_INC	=	include
DIR_SRC	=	src

RM	=	rm -f

$(NAME):
	@make bonus -C libft
	$(CC) $(CFLAGS) $(SRCS)  $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C libft
		@echo "Object files of Pipex has removed"

fclean: clean
		@$(RM) $(NAME)
		@echo "Pipex has removed"

re: fclean all

norm:
	@echo "---------------- Libft -------------------"
	@make norm -C libft
	@echo "------------------------------------------\n"
	@echo "---------------- PIPEX -------------------"
	@norminette $(SRCS) $(DIR_INC)	
	@echo "------------------------------------------\n"
