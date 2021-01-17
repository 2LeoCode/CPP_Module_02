# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 20:55:10 by lsuardi           #+#    #+#              #
#    Updated: 2021/01/17 21:07:46 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		eval_expr

SRC =		main.cpp\
			Fixed.class.cpp
OBJ =		$(SRC:.cpp=.o)

OBJDIR =	.obj

CFLAGS =	-Wall\
			-Werror\
			-Wextra

all: $(OBJDIR) $(NAME)
	@echo '$(NAME) is up to date.'

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@(\
		echo '\nCompiling $@';\
		clang++ $(CFLAGS) $^ -o $@\
	)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)/%.o: %.cpp
	@(\
		printf '\033[2K\rCompiling $<';\
		clang++ $(CFLAGS) -c $< -o $@\
	)

clean:
	@(\
		rm -rf $(OBJDIR);\
		echo 'Removed $(OBJDIR)'\
	)

fclean: clean
	@(\
		rm -f $(NAME);\
		echo 'Removed $(NAME)'\
	)

re: fclean all
