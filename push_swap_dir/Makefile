CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap

HEADERS	= ./includes 

SOURCES	= ./error.c			./main.c			./parser.c				\
	./parser_opt.c			./cmd/instruction.c		./cmd/push.c				\
	./cmd/rr.c			./cmd/rrr.c			./cmd/ss.c				\
	./lst/find_next_above.c		./lst/get_elem_above.c		./lst/lst_del.c				\
	./lst/lst_dup.c			./lst/lst_last.c		./lst/lst_len.c				\
	./lst/lst_median.c		./lst/lst_new.c			./lst/lst_push_instru.c			\
	./lst/lst_pushback_unique.c	./lst/lst_reorder.c		./lst/lst_size.c			\
	./solver/calc_move.c		./solver/get_better_push.c	./solver/get_next_partition.c		\
	./solver/parse_a.c		./solver/resolve_b.c		./solver/split_rec_b.c			\
	./solver/update_index.c		

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ)

clean	: 
	rm -f $(OBJ)

re	: fclean all

fclean	: clean
	rm -f $(NAME)

