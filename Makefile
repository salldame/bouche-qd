##
## Makefile for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
##
## Made by benjamin lehellaye
## Login   <lehell_b@epitech.net>
##
## Started on  Tue Feb  7 17:16:35 2012 benjamin lehellaye
## Last update Mon Mar 26 16:09:11 2012 kevin boucher
##

NAME		= 42sh

SRC		= fonction.c		\
		  start.c	\
		  fonction2.c		\
		  environ.c		\
		  my_function.c		\
		  minishell2.c		\
		  my_str_to_word_tab.c	\
		  aff_intro.c

OBJ		= $(SRC:.c=.o)

CC		= cc

LIB		= -lmlx -lXext -lX11 -lm

CFLAGS		= -g -Wall -Wextra -pedantic -ansi

RM		= rm -f

$(NAME)		: $(OBJ)
		  $(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) -g
		make clean

all		: $(NAME)

clean		:
		  $(RM) \#*#
		  $(RM) *~
		  $(RM) $(OBJ)

fclean		: clean
		  $(RM) $(NAME)

re		: fclean all