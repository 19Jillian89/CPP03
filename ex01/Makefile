# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/13 22:26:48 by ilnassi           #+#    #+#              #
#    Updated: 2026/09/13 22:27:33 by ilnassi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = scavtrap
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

INC_DIR     = includes
SRC_DIR     = src

SRCS        = main.cpp \
              $(SRC_DIR)/ScavTrap.cpp \
              $(SRC_DIR)/ClapTrap.cpp

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
