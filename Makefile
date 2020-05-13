FLAG = -g -std=c99 -Werror -Wextra -Wall

NAME = ft_ls

SRC =	read_flag_input.c \
			process_flag.c\
			testls.c \
			arrange_turn.c\
			array_length.c\
			choose_flag.c\
			chosen_flag.c\
			delete.c\
			file_content_count.c\
			file_info.c\
			filepath.c\
			folder.c\
			ft_sortit.c\
			user_details.c\
			no_flag.c\
			number_read_bytes.c\
			open_read_folder_flag.c\
			open_read_folder.c\
			reverse_order.c\
			skip_first_param.c\
			sort_by_time.c\
			struct_sort.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a
	echo "$(NAME) Created"

$(OBJ): %.o: %.c
	gcc $(FLAG) -c $< -o $@
	echo "Objects created"

clean:
	rm -rf *.o
	echo "Objects deleted"

fclean: clean
	rm -rf $(NAME)
	echo "$(NAME) Deleted"

re: fclean all

re: fclean all