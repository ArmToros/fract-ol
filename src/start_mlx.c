#include "fractol.h"

// void	start_mandelbrot(void)
// {
// 	t_fractol	f;

// 	// Initialize MLX
// 	f.mlx = mlx_init();
// 	if (!f.mlx)
// 		exit(EXIT_FAILURE);

// 	// Create window and image
// 	f.type = MANDELBROT;
// 	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot");
// 	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
// 	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);

// 	// Set initial zoom and position
// 	f.zoom = 1.0;
// 	f.offset_x = 0.0;
// 	f.offset_y = 0.0;

// 	// Initial draw
// 	draw_mandelbrot(&f);

// 	// Hook events
// 	mlx_hook(f.win, 17, 1L<<0, close_window, &f);     // [X] close
// 	mlx_key_hook(f.win, handle_key, &f);          // ESC
// 	mlx_mouse_hook(f.win, handle_mouse, &f);      // Zoom scroll

// 	// Start event loop
// 	mlx_loop(f.mlx);
// }

// void	start_burning_ship(void)
// {
// 	t_fractol	f;

// 	// Init MLX
// 	f.mlx = mlx_init();
// 	if (!f.mlx)
// 		exit(EXIT_FAILURE);

// 	// Create window and image
// 	f.type = BURNING_SHIP;
// 	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Burning Ship");
// 	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
// 	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);

// 	// Init zoom/offset
// 	f.zoom = 1.0;
// 	f.offset_x = -1.0;
// 	f.offset_y = -1.0;

// 	// Draw the fractal
// 	draw_burning_ship(&f);

// 	// Hooks
// 	mlx_hook(f.win, 17, 1L<<0, close_window, &f);
// 	mlx_key_hook(f.win, handle_key, &f);
// 	mlx_mouse_hook(f.win, handle_mouse, &f);

// 	// Event loop
// 	mlx_loop(f.mlx);
// }

void start(int check)
{
    t_fractol	f;

	// Init MLX
	f.mlx = mlx_init();
	if (!f.mlx)
		exit(EXIT_FAILURE);

	// Create window and image
    if(check == 1)
	    f.type = BURNING_SHIP;
    else
	    f.type = MANDELBROT;
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Burning Ship");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.line_len, &f.endian);
	// Init zoom/offset
	f.zoom = 1.0;
	f.offset_x = check * - 1;
	f.offset_y = check * - 1;
    f.color_set = 0;
    f.julia_re = 0;
    f.julia_im = 0;
    f.julia_mouse_lock = 0;
	// Draw the fractal
    if(check == 1)
	    draw_burning_ship(&f);
    else
    {
        draw_mandelbrot(&f);
    }
	// Hooks
	mlx_hook(f.win, 17, 1L<<0, close_window, &f);
	mlx_key_hook(f.win, handle_key, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	// Event loop
	mlx_loop(f.mlx);
}

void	start_julia(t_fractol *f, double x, double y)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Julia Set");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);

	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->type = JULIA;
    f->color_set = 0;
	f->julia_mouse_lock = 0;
	f->julia_re = x;
	f->julia_im = y;

	draw_julia(f);
	mlx_key_hook(f->win, handle_key, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	
	//this is for mouse
	mlx_loop_hook(f->mlx, loop_hook, f);

	mlx_hook(f->win, 17, 1L<<0, close_window, f);
	mlx_loop(f->mlx);
}