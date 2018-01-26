# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/16 11:32:42 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2018/01/26 17:59:52 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =		fdf

INC_DIR =	./inc/

SRC_DIR =	./src/

OBJ_DIR =	./obj/

C_FILES =	main.c	input.c	output.c constructors.c	env.c destructors.c

O_FILES =	$(C_FILES:.c=.o)

SOURCES =	$(addprefix $(SRC_DIR), $(C_FILES))

OBJECTS =	$(addprefix $(OBJ_DIR), $(O_FILES))

CC =		gcc

CC_FLAGS =	-Wall -Werror -Wextra

I_LIBFT =	./libft/inc

INC_MLX =	-L minilibx/ -lmlx -framework OpenGL -framework AppKit -I ./minilibx/

all: $(NAME)

$(NAME):$(OBJECTS)
	@make -C libft
	@make -C minilibx
	@$(CC) $(CC_FLAGS) $(OBJECTS) -L libft/ -lft -o $(NAME) $(INC_MLX)
	@echo "$(NAME) is ready :)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)fdf.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(I_LIBFT) -I ./minilibx/

clean:
	@make clean -C libft
	@make clean -C minilibx
	@rm -fr $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@make clean -C minilibx
	@rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
