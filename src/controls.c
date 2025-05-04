/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:30:38 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 13:14:09 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void handle_key_util0(int keycode, t_fractol *f)
{
	double move_step = 0.1 * f->zoom;
	if (keycode == 65361)
		f->offset_x -= move_step;
	if (keycode == 65363)
		f->offset_x += move_step;
	if (keycode == 65362)
		f->offset_y -= move_step;
	if (keycode == 65364)
		f->offset_y += move_step;
	else if (keycode == 99)
		f->color_set = (f->color_set + 1) % 3;
}

static void handle_key_util1(int keycode, t_fractol *f)
{
	if (keycode == 49) // '1' key (Mandelbrot)
	{
		f->type = MANDELBROT;
		f->zoom = 1.0;
		f->offset_x = 0.0;
		f->offset_y = 0.0;
	}
	else if (keycode == 50) // '2' key (Julia)
	{
		f->type = JULIA;
		f->zoom = 1.0;
		f->offset_x = 0.0;
		f->offset_y = 0.0;
		f->julia_mouse_lock = 0;
		mlx_loop_hook(f->mlx, loop_hook, f);
	}
	else if (keycode == 51) // '3' key (Burning Ship)
	{
		f->type = BURNING_SHIP;
		f->zoom = 1.0;
		f->offset_x = -1.0;
		f->offset_y = -1.0;
	}
}
static void handle_key_util2(int keycode, t_fractol *f)
{
	if (keycode == 61 || keycode == 65451) // '+' key
		f->zoom *= 0.9;
	else if (keycode == 45 || keycode == 65453) // '-' key
		f->zoom *= 1.1;
}
int	handle_key(int keycode, t_fractol *f)
{
	handle_key_util0(keycode,f);
	handle_key_util1(keycode,f);
	handle_key_util2(keycode,f);
	if (keycode == 65307) // ESC key code
	{
		close_clean_window(f);		
	}
	else if (keycode == 106) // 'j' key in ASCII
	{
		f->julia_mouse_lock = !f->julia_mouse_lock;
	}
	if (f->type == MANDELBROT)
		draw_mandelbrot(f);
	else if (f->type == JULIA)
		draw_julia(f);
	else if (f->type == BURNING_SHIP)
		draw_burning_ship(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	close_clean_window(f);
	return (0);
}
