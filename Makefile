NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER		=	includes/pipex_bonus.h

PATH		=	pipex.c error.c files.c\
				free.c child.c
OBJ		=	$(PATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c\
				ft_strlen.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ)
				@$(CC) $(OBJ_F) $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean bonus re

