/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:05 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 16:45:51 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	handle_key_util0(int keycode, t_fractol *f)
{
	if (keycode == 65361)
	{
		f->offset_x -= 0.1 * f->zoom;
		control_draw(f);
	}
	else if (keycode == 65363)
	{
		f->offset_x += 0.1 * f->zoom;
		control_draw(f);
	}
	else if (keycode == 65362)
	{
		f->offset_y -= 0.1 * f->zoom;
		control_draw(f);
	}
	else if (keycode == 65364)
	{
		f->offset_y += 0.1 * f->zoom;
		control_draw(f);
	}
	else if (keycode == 99)
	{
		f->color_set = (f->color_set + 1) % 3;
		control_draw(f);
	}
}

static void	handle_key_util1(int keycode, t_fractol *f)
{
	if (keycode == 49)
	{
		f->type = MANDELBROT;
		start_util(f, 1.0, 0.0, 0.0);
		control_draw(f);
	}
	else if (keycode == 50)
	{
		f->type = JULIA;
		start_util(f, 1.0, 0.0, 0.0);
		f->julia_mouse_lock = 0;
		control_draw(f);
		mlx_loop_hook(f->mlx, loop_hook, f);
	}
	else if (keycode == 51)
	{
		f->type = BURNING_SHIP;
		start_util(f, 1.0, -1.0, -1.0);
		control_draw(f);
	}
}

static void	handle_key_util2(int keycode, t_fractol *f)
{
	if (keycode == 61 || keycode == 65451)
	{
		f->zoom *= 0.9;
		control_draw(f);
	}
	else if (keycode == 45 || keycode == 65453)
	{
		f->zoom *= 1.1;
		control_draw(f);
	}
}

int	handle_key(int keycode, t_fractol *f)
{
	handle_key_util0(keycode, f);
	handle_key_util1(keycode, f);
	handle_key_util2(keycode, f);
	if (keycode == 65307)
	{
		close_clean_window(f);
	}
	else if (keycode == 106)
		f->julia_mouse_lock = !f->julia_mouse_lock;
	return (0);
}

int	close_window(t_fractol *f)
{
	close_clean_window(f);
	return (0);
}
