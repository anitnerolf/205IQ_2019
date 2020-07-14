##
## EPITECH PROJECT, 2020
## 205IQ
## File description:
## makefile
##

SRC	=	src/Main.cpp	\
		src/IQ.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	205IQ

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -lm -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
