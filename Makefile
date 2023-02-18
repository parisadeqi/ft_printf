# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: psadeghi <psadeghi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/31 18:32:09 by psadeghi      #+#    #+#                  #
#    Updated: 2022/11/01 16:53:14 by psadeghi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = ft_printf.c ft_convertdectohexup.c ft_convertdectohexlow.c ft_printptr.c\
		ft_putchar.c

OBJFILES = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJFILES)

fclean :
	rm -f $(OBJFILES) $(NAME)

re: fclean all

.PHONY : all clean fclean re