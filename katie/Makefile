# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/27 21:09:44 by nhariman      #+#    #+#                  #
#    Updated: 2020/08/25 04:12:31 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = clang++

FLAGS = -Wall -Werror -Wextra -std=c++11 -Wsizeof-pointer-div

FILES = main.cpp \
		nyms.cpp

OFILES = $(FILES:.cpp=.o)

NAME = nyms

all: $(NAME)

$(NAME): $(OFILES)
	@$(COMPILE) $(OFILES) -o $@

%.o: %.cpp nyms.hpp
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all