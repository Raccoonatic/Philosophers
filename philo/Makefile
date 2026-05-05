# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 19:37:56 by lde-san-          #+#    #+#              #
#    Updated: 2026/05/03 23:22:00 by lde-san-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
PHILO_LIB = libphilo.a

ARGS ?= 1

NEOR	= \033[3m\033[38;2;255;153;51m
MINT    = \033[1;38;2;55;250;133m
ORNG    = \033[1;38;2;255;153;51m
PURP	= \033[1;38;2;174;5;252m
PINK    = \033[1;38;2;255;0;251m
BABY    = \033[1;38;2;0;255;247m
BLOD	= \033[1;38;2;255;0;0m
LIME    = \033[1;38;2;0;255;0m
BLAK	= \033[1;38;2;0;0;0m
B_WI    = \033[1;37m
RSET	= \033[0m

OBJ_DIR = obj/
OBJ = $(FILE:%.c=$(OBJ_DIR)%.o)

MAIN_FILE = philo_main.c

FILE = philo_simulation.c
FILE += philo_simulation_utils.c
FILE += philo_utils_alpha.c
FILE += philo_utils_beta.c
FILE += philo_utils_charlie.c

.PRECIOUS: $(FILE)

COMPILE = cc -g -O0 -Wall -Werror -Wextra -pthread -I.
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
THREAD_FLAGS = --tool=helgrind

all: $(NAME)

$(NAME): $(PHILO_LIB) $(MAIN_FILE) philo.h
	@printf "$(BABY)"
	$(COMPILE) $(MAIN_FILE) $(PHILO_LIB) -o $(NAME)
	@printf "$(RSET)\n"

$(OBJ_DIR)%.o: %.c philo.h | $(OBJ_DIR)
	@printf "$(PURP)"
	$(COMPILE) -c $< -o $@
	@printf "$(RSET)\n"

$(OBJ_DIR):
	@printf "$(LIME)"
	mkdir -p $(OBJ_DIR)
	@printf "$(RSET)\n"

$(PHILO_LIB): $(OBJ)
	@printf "$(PINK)"
	ar -rcs $@ $^
	@printf "$(RSET)\n"

clean:
	@printf "$(ORNG)"
	rm -rf $(OBJ_DIR)
	@printf "$(BLOD)"
	rm -rf $(PHILO_LIB)
	@printf "$(RSET)\n"

fclean: clean
	@printf "$(PURP)"
	rm -f $(NAME)
	@rm -rf normloop.sh
	@printf "$(MINT)\n"
	@ls -la
	@printf "$(RSET)\n"

re: fclean all

# /////////////////////// -- * Functionality * -- ////////////////////// #

open:
	@printf "$(MINT)"
	open $(MAIN_FILE)
	for f in $(FILE); do xdg-open $$f; done
	@printf "$(ORNG)"
	find . -maxdepth 2 -name "*.h" -exec xdg-open {} \;
	@printf "$(RSET)"

leaks: $(NAME)
	@printf "\n$(PINK)valgrind $(ORNG)$(LEAK_FLAGS) $(MINT)./$(NAME) $(BABY)$(ARGS)"
	@printf "$(RSET)\n"
	@valgrind $(LEAK_FLAGS) ./$(NAME) $(ARGS)
	@sleep 0.3

races: $(NAME)
	@printf "\n$(PINK)valgrind $(ORNG)$(THREAD_FLAGS) $(MINT)./$(NAME) $(BABY)$(ARGS)"
	@printf "$(RSET)\n"
	@valgrind $(THREAD_FLAGS) ./$(NAME) $(ARGS)
	@sleep 0.3

normloop:
	@printf "$(NEOR) Building normloop.sh... $(RESET)"
	@sleep 0.5
	@printf "$(MINT)🦝\n\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'#                                                       :::      ::::::::  #'\n"
	@printf "$(BABY)'#  normloop.sh                                        :+:      :+:    :+:  #'\n"
	@printf "$(BABY)'#                                                   +:+ +:+         +:+    #'\n"
	@printf "$(BABY)'#  By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+       #'\n"
	@printf "$(BABY)'#                                               +#+#+#+#+#+   +#+          #'\n"
	@printf "$(BABY)'#  Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#            #'\n"
	@printf "$(BABY)'#  Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr      #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@> normloop.sh
	@printf "%s\n" '#!/bin/bash'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '#                                                         :::      ::::::::    #'>> normloop.sh
	@printf "%s\n" '#    normloop.sh                                        :+:      :+:    :+:    #'>> normloop.sh
	@printf "%s\n" '#                                                     +:+ +:+         +:+      #'>> normloop.sh
	@printf "%s\n" '#    By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+         #'>> normloop.sh
	@printf "%s\n" '#                                                 +#+#+#+#+#+   +#+            #'>> normloop.sh
	@printf "%s\n" '#    Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#              #'>> normloop.sh
	@printf "%s\n" '#    Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr        #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'trap '\''rm -f tody.txt; exit'\'' INT'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'if [ -n '\"'$$1'\"' ]; then'>> normloop.sh
	@printf "%s\n" '	FILE='\"'$$1'\"''>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader '\"'$$FILE'\"' | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '		clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'else'>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader *.c | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '        clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'fi'>> normloop.sh
	@chmod 777 normloop.sh
	@printf "$(RESET)🦝"

.PHONY: all clean fclean re open normloop leaks
