/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:41 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 16:46:56 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
	mouse_im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;
	if (button == 4)
		f->zoom *= 0.9;
	else if (button == 5)
		f->zoom *= 1.1;
	f->offset_x = mouse_re - ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom;
	f->offset_y = mouse_im - ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom;
	control_draw(f);
	return (0);
}

int	loop_hook(void *param)
{
	t_fractol	*f;
	int			x;
	int			y;

	f = (t_fractol *)param;
	if (f->type == JULIA && f->julia_mouse_lock)
	{
		mlx_mouse_get_pos(f->mlx, f->win, &x, &y);
		f->julia_re = ((double)(x - WIDTH / 2)*4.0 / WIDTH) * f->zoom
			+ f->offset_x;
		f->julia_im = ((double)(y - HEIGHT / 2)*4.0 / HEIGHT) * f->zoom
			+ f->offset_y;
		draw_julia(f);
	}
	return (0);
}

int	close_clean_window(t_fractol *f)
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

void	control_draw(t_fractol *f)
{
	if (f->type == MANDELBROT)
		draw_mandelbrot(f);
	else if (f->type == JULIA)
		draw_julia(f);
	else if (f->type == BURNING_SHIP)
		draw_burning_ship(f);
}

void	start_util(t_fractol *f, double z, double x, double y)
{
	f->zoom = z;
	f->offset_x = x;
	f->offset_y = y;
}
