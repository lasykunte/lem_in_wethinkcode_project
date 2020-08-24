CC = gcc

LIB = ./libft/libft.a

NAME = lem-in_

FLAGS = -Wall -Wextra -Werror -I.

SRCC =	./lem-in/lem_in.c ./lem-in/backtracking.c\
		./lem-in/ants_num_count.c ./lem-in/edge_links.c \
		./lem-in/rooms_vertex.c ./lem-in/freefunction_exit.c\
		./lem-in/sum_room_vertex.c ./lem-in/adjacency_matrix.c\
		./lem-in/display_matrix.c ./lem-in/display_results.c\
		./lem-in/room_vertex_indx.c ./lem-in/combine_ant_string.c\
		./lem-in/free_arr_mem.c
		
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