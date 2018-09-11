CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= checker

HEADERS	= ./includes ./libft/includes

SOURCES	= ./clear.c			./error.c			./main.c				\
	./parser.c			./parser_opt.c			./cmd/push.c				\
	./cmd/rr.c			./cmd/rrr.c			./cmd/ss.c				\
	./lst/calc_move.c		./lst/lst_del.c			./lst/lst_pushback_unique.c		\
	./lst/lst_reorder.c		./lst/lst_size.c		

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

makelib	: 
	make -C libft/

cleanlib	: 
	make clean -C libft/

fcleanlib	: 
	make fclean -C libft/

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)

