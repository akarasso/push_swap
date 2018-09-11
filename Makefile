NAME = ps

all	: $(NAME)

$(NAME)	:
	make -C checker_dir/
	make -C push_swap_dir/
	cp checker_dir/checker .
	cp push_swap_dir/push_swap .

clean	: 
	make clean -C checker_dir/
	make clean -C push_swap_dir/

re	: fclean $(NAME)

fclean	: clean
	make fclean -C checker_dir/
	make fclean -C push_swap_dir/
	rm -f checker
	rm -f push_swap
