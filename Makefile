CC = gcc

LIB = ./libft/libft.a

NAME = lem-ins

FLAGS = -Wall -Wextra -Werror -I.

SRCC =	./lem_in/lem_in.c ./lem_in/adjacency_matrix.c\
		./lem_in/ants_num_count.c ./lem_in/free_arr_mem.c\
		./lem_in/freefuntion_exit.c ./lem_in/backtracking.c\
		./lem_in/combine_ant_string.c ./lem_in/display_matrix.c\
		./lem_in/display_results.c ./lem_in/edge_links.c\
		./lem_in/room_vertex_indx.c ./lem_in/rooms_vertex.c\
		./lem_in/sum_room_vertex.c

all: $(NAME)

$(NAME):

		make -C ./libft
		$(CC) $(FLAGS) -o $(NAME) $(SRCC) $(LIB)

clean:
		rm -fr $(SRCO)
		make clean -C ./libft
fclean: clean
		rm -fr $(NAME)
		make fclean -C ./libft

re: fclean all