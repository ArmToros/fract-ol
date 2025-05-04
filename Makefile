NAME = fractol

SRC = src/main.c src/mandelbrot.c src/utils.c src/julia.c src/controls.c \
		src/burning_ship.c src/utils_atod.c src/controls_utils.c src/start_mlx.c
OBJ = $(SRC:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lX11 -lXext -lm -lbsd

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx

all: $(NAME)

$(NAME): $(OBJ)
	# @make all -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
