NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils_str.c \
			ft_printf_utils_nbr.c \
			ft_printf_utils_specific.c

HEADER	=	ft_printf.h

FLAGS	=	-Wall -Werror -Wextra -I.

OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc

.PHONY	:	all clean fclean re

$(NAME)	:	$(OBJ)
			ar r $(NAME) $?

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

all		:	$(NAME)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf  $(NAME)

re		:	fclean all
