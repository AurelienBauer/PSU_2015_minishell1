##
## Makefile for  in /home/aurelien/rendu/PSU_2015_my_ls
## 
## Made by Aurélien
## Login   <aurelien.bauer@epitech.net>
## 
## Started on  Thu Nov 26 15:34:08 2015 Aurélien
## Last update Sat Feb 13 12:24:09 2016 Aurélien
##

RM	= rm -f									\

CC	= gcc -g								\

NAME	= mysh									\

CFLAGS	= -lmy -L ./lib -I ./include -g						\

SRCS	= mysh.c		\
	  env.c			\
	  anex_fonction.c	\
	  cd.c			\
	  pass_env_exec.c

OBJS	= $(SRCS:.c=.o)								\

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *~

re: fclean all

.PHONY: all clean re
