CC = gcc

LIB = ./libft/libft.a

NAME = lem-in

FLAGS = -Wall -Wextra -Werror -I.

SRCC =	./lem_in/ants_num_count.c ./lem_in/combine_ant_string.c\
		./lem_in/check_sorted.c ./lem_in/free_stack_ab.c\
		./lem_in/push_pa.c ./lem_in/push_pb.c ./lem_in/reverse_rotate_rra.c\
		./lem_in/reverse_rotate_rrb.c ./lem_in/reverse_rotate_rrr.c\
		./lem_in/rotate_ra.c ./lem_in/rotate_rb.c ./lem_in/rotate_rr.c\
		./lem_in/stack_ab.c ./lem_in/swap_sa.c ./lem_in/swap_sb.c\
		./lem_in/swap_ss.c

SRCS = ./lem_in/stack_ab.c ./lem_in/push_pa.c ./lem_in/push_pb.c\
		./lem_in/rotate_ra.c ./lem_in/rotate_rb.c ./lem_in/rotate_rr.c\
		./lem_in/reverse_rotate_rra.c ./lem_in/reverse_rotate_rrb.c\
		./lem_in/reverse_rotate_rrr.c ./lem_in/swap_sa.c ./lem_in/swap_sb.c\
		./lem_in/swap_ss.c ./lem_in/free_stack_ab.c ./pushswap/check_sorted_stack_a.c\
		./pushswap/evaluate_sort_command.c ./pushswap/push_swap.c\
		./pushswap/sort_left_partition.c ./pushswap/sort_right_partition.c

all: $(NAME)

$(NAME):

		make -C ./libft
		$(CC) $(FLAGS) -o $(NAME) $(SRCC) $(LIB)

clean:
		rm -fr $(SRCO)
		make clean -C ./libft
fclean: clean
		rm -fr $(NAME)
		rm -fr $(NAME1)
		make fclean -C ./libft

re: fclean all