# имя выходного файла
NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils_str.c \
			ft_printf_utils_nbr.c \
			ft_printf_utils_specific.c

OBJ		=	$(SRCS:%.c=%.o)

HEADER	=	ft_printf.h

FLAGS	=	-Wall -Wextra - Werror

CC		= 	gcc

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar r $(NAME) $^

%.o		:	%.c $(HEADER)
			$(CC) $(FLAFS) -c $(SRCS)

clean	:
			@rm -rf $(OBJ) $(OBJ_B)

fclean	:	clean
			@rm -rf $(NAME)

re		:	fclean all
