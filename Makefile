# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angela <angela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 22:57:11 by angela            #+#    #+#              #
#    Updated: 2023/09/04 10:44:29 by angela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			= push_swap
RM				= rm -f
CC				= gcc

# ---------------- Color --------------
GREEN			=		\033[1;32m
DARKGRAY		=		\033[1;30m
LIGHTGRAY		=		\033[1;37m
PURPLE			=		\033[0;35m
LIGHTPURPLE		=		\033[1;35m
LIGHTCYAN		=		\033[1;36m
LILAC			= 		\033[0;94m    
ENDCOLOR		=		\033[0m

# ---------------- FLAGS --------------
CFLAGS			= -Wall -Wextra -Werror 
NUMTEST			= "4 1 3 5"
DEBUG			= -fsanitize=address -g3

# ---------------- Sources -----------
SRC				=	./src/main.c \
					./src/ft_printf/ft_printf.c \
					./src/ft_printf/s_c_p_d_i.c \
				 	./src/ft_printf/u_x_X.c \
					./src/check_errors.c \
					./src/utils.c \
					./src/check.c \
					./init/init_list.c \
					./src/operation/swap.c \
					./src/operation/rotate.c \
					./src/operation/reverse_rotate.c \
					./src/operation/push.c \
					./src/sorting/sorting_under_5.c \
					./src/sorting/sorting_more.c \
					./src/sorting/index.c
					

					
				 
LIB				= ./includes/push_swap.h
			

# ---------------- Objets -----------
OBJS			= ${SRC:.c=.o}


# --------------- LIBFT --------------------

LIBFT			=		./libft/libft.a
MLIBFT			=		@$(MAKE) -C libft

#lib:
#			@$(MLIBFT) all
#			@$(END_COMP_LIB_TXT)

# --------------- Regles --------------------

all:			${NAME} lib clean

lib:
			@$(MLIBFT)
			
%.o:		%.c ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE_TXT)

${NAME}:		${OBJS}
				@make -C libft
				@${CC} ${CFLAGS} ${DEBUG} -o ${NAME} ${OBJS} ${LIBFT}
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

				@echo "$(GREEN)Compilation of push_swap is done!🚀$(ENDCOLOR)"

rleak:
				@leaks --atExit -- ./${NAME} ${NUMTEST}
#.c.o:
#				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# --------------- VISUEL --------------------
BS_TXT			= echo "\n\n\n\n"
start_msg:
				@$(BS_TXT)
				@tput setaf 92; cat ascii_art/cat_make; tput setaf 7
				@$(BS_TXT)





# --------------- Service nettoyage --------------------
clean:
				@$(BS_TXT)
				@tput setaf 128; cat ascii_art/cat_clean; tput setaf 13
				@$(BS_TXT)
				@${RM} ${OBJS}


fclean:			clean
				@tput setaf 189; cat ascii_art/cat_fclean; tput setaf 9
				@$(BS_TXT)	
				@${RM} ${NAME}
				@echo "$(GREEN)Cleaning succes🌸$(ENDCOLOR)"

re:				fclean all 
				@tput setaf 183; cat ascii_art/cat; tput setaf 7
				@$(BS_TXT)

rel:			fclean leaks

norm :
				@norminette ${SRC}
				@norminette ${LIB}
				@echo "$(PURPLE)Nooooorminetto$(ENDCOLOR)"
				@$(BS_TXT)

.PHONY : all clean fclean re norm leaks rel libft