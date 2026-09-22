# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/13 22:26:48 by ilnassi           #+#    #+#              #
#    Updated: 2026/09/22 10:40:47 by ilnassi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = diamondtrap
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -Wno-shadow -std=c++98 -I$(INC_DIR)

INC_DIR     = includes
SRC_DIR     = src

SRCS        = main.cpp \
              $(SRC_DIR)/ClapTrap.cpp \
              $(SRC_DIR)/ScavTrap.cpp \
              $(SRC_DIR)/FragTrap.cpp \
              $(SRC_DIR)/DiamondTrap.cpp
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
