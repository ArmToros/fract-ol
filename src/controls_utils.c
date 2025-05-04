/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:39:02 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 13:13:33 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	double	mouse_re;
	double	mouse_im;

	// Convert mouse (x, y) to complex plane coordinates
	mouse_re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
	mouse_im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;

	if (button == 4) // scroll up = zoom in
		f->zoom *= 0.9;
	else if (button == 5) // scroll down = zoom out
		f->zoom *= 1.1;

	// Adjust offset to keep zoom centered under mouse
	f->offset_x = mouse_re - ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom;
	f->offset_y = mouse_im - ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom;

	if (f->type == MANDELBROT)
	    draw_mandelbrot(f);
    else if (f->type == JULIA)
	    draw_julia(f);
	else if (f->type == BURNING_SHIP)
		draw_burning_ship(f);

	return (0);
}

int loop_hook(void *param)
{
	t_fractol *f = (t_fractol *)param;
	int x, y;
	if (f->type == JULIA && f->julia_mouse_lock)
	{
		mlx_mouse_get_pos(f->mlx, f->win, &x, &y);
		f->julia_re = ((double)(x - WIDTH / 2) * 4.0 / WIDTH) * f->zoom + f->offset_x;
		f->julia_im = ((double)(y - HEIGHT / 2) * 4.0 / HEIGHT) * f->zoom + f->offset_y;
		draw_julia(f);
	}
    return (0);
}

int close_clean_window(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}