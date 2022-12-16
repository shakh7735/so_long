NAME = so_long

CC = cc

CFLAGS = -Werror -Wall -Wextra

SRC = game_main.c\
		animation.c\
		chek_map.c\
		create_screen.c\
		game_init.c\
		input_key.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		ft_printf/ft_printf.c\
		ft_printf/utils/ft_print_char.c\
		ft_printf/utils/ft_printf_utils.c\
		ft_printf/utils/ft_print_num.c\
		ft_printf/utils/ft_print_ptr.c\
		ft_printf/utils/ft_print_str.c\
		ft_printf/utils/ft_print_u.c\
		ft_printf/utils/ft_print_xX.c\
		ft_printf/utils/ft_putnbr.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C ./minilibx
		$(CC) $(OBJ) libmlx.dylib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
		rm -rf $(OBJ) 

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re