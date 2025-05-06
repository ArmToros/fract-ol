/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:39 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/06 20:50:40 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_common(t_fractol *f)
{
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->zoom = 1.0;
	f->color_set = 0;
	f->julia_mouse_lock = 0;
}

static void	start_utils(t_fractol *f, int check)
{
	if (check == 1)
		f->type = BURNING_SHIP;
	else
		f->type = MANDELBROT;
	init_common(f);
}

void	start(int check)
{
	t_fractol	f;

	f.mlx = mlx_init();
	if (!f.mlx)
		exit(EXIT_FAILURE);
	start_utils(&f, check);
	f.offset_x = check * -1;
	f.offset_y = check * -1;
	f.julia_re = 0;
	f.julia_im = 0;
	if (check == 1)
		draw_burning_ship(&f);
	else
		draw_mandelbrot(&f);
	mlx_hook(f.win, 17, 1L << 0, close_window, &f);
	mlx_key_hook(f.win, handle_key, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	mlx_loop(f.mlx);
}

void	start_julia(t_fractol *f, double x, double y)
{
	f->mlx = mlx_init();
	init_common(f);
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->type = JULIA;
	f->julia_re = x;
	f->julia_im = y;
	draw_julia(f);
	mlx_key_hook(f->win, handle_key, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
	mlx_hook(f->win, 17, 1L << 0, close_window, f);
	mlx_loop(f->mlx);
}
