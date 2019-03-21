##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	=	navy

SRC	=	./src/main.c\
		./src/map.c\
		./src/print_map.c\
		./src/my_get_nbr.c\
		./src/serv.c\
		./src/get_next_line.c\
		./src/parser.c\
		./src/parserenemy.c\
		./src/goodfile.c\
		./src/my_error.c\
		./src/my_strlen.c\
		./src/full.c\
		./src/fulltwo.c\
		./src/sig_gen.c\
		./src/client.c\
		./src/defence.c\
		./src/attack.c\
		./src/checkwinclient.c\
		./src/checkwinserv.c\
		./src/receptionserv.c\
		./src/fullthree.c\

CFLAGS	=	 -g3 -I ./include/

LDFLAGS	=	-L . -l my

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./my_printf
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	@rm -f $(OBJ)

clean:
	@make clean -C ./my_printf
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C ./my_printf
	@rm -f $(NAME)

re: fclean all
