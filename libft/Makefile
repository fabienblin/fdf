# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/28 17:35:55 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2018/01/08 12:27:43 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRC_DIR =	./src/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

NAME =		libft.a

FABLIN =	ft_exit.c		ft_realloc.c	ft_lstpush.c	ft_lstdup.c		\
			ft_swapptr.c	get_next_line.c	ft_strjoinfree.c

BONUS =		ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		\
			ft_lstiter.c	ft_lstmap.c

CFILES =	ft_memset.c		ft_strcat.c		ft_isdigit.c	ft_striter.c	\
			ft_putchar.c 	ft_bzero.c		ft_strncat.c	ft_isalnum.c	\
			ft_striteri.c	ft_putstr.c		ft_memcpy.c		ft_strlcat.c	\
			ft_isascii.c	ft_strmap.c		ft_putendl.c	ft_memccpy.c	\
			ft_strchr.c		ft_isprint.c	ft_strmapi.c	ft_putnbr.c		\
			ft_memmove.c	ft_strrchr.c	ft_toupper.c	ft_strequ.c		\
			ft_putchar_fd.c	ft_memchr.c		ft_strstr.c		ft_tolower.c	\
			ft_strnequ.c	ft_putstr_fd.c	ft_memcmp.c		ft_strnstr.c	\
			ft_memalloc.c	ft_strsub.c		ft_putendl_fd.c	ft_strlen.c		\
			ft_strcmp.c		ft_memdel.c		ft_strjoin.c	ft_putnbr_fd.c	\
		 	ft_strdup.c		ft_strncmp.c	ft_strnew.c		ft_strtrim.c	\
			ft_strcpy.c		ft_atoi.c		ft_strdel.c		ft_strsplit.c	\
			ft_strncpy.c	ft_isalpha.c	ft_strclr.c		ft_itoa.c		\
			$(BONUS)		$(FABLIN)

SOURCES =	$(addprefix $(SRC_DIR), $(CFILES))

OFILES =	$(CFILES:.c=.o)

OBJECTS =	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SOURCES) -I $(INC_DIR)
	@ar rc $(NAME) $(OFILES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OFILES) $(OBJ_DIR)
	@echo "\n===> LIBFT HAS BEEN COMPILED <===\n"

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re : fclean all

.PHONY: all clean fclean re
