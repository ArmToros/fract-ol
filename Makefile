NAME = fractol

SRC = src/main.c src/mandelbrot.c src/utils.c src/julia.c src/controls.c \
	  src/burning_ship.c src/utils_atod.c src/controls_utils.c src/start_mlx.c
OBJ = $(SRC:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lX11 -lXext -lm -lbsd

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	# @make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)

clean:
	@rm -f $(OBJ)
	# @make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	# @make clean -C $(MLX_DIR)

re: fclean all

PHONY: all clean fclean re