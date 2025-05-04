/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:33 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 15:04:35 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_mandelbrot_pixel(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			iter;

	c.re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
	c.im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while ((z.re * z.re + z.im * z.im <= 4.0) && (iter < MAX_ITER))
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		iter++;
	}
	my_mlx_pixel_put(f, x, y, get_color(iter, f->color_set));
}

void	draw_mandelbrot(t_fractol *f)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_mandelbrot_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
