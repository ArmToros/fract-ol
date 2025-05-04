/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:17 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 15:04:21 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_julia_pixel(t_fractol *f, int x, int y, t_complex c)
{
	t_complex	z;
	double		temp;
	int			i;

	z.re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
	z.im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		i++;
	}
	my_mlx_pixel_put(f, x, y, get_color(i, f->color_set));
}

void	draw_julia(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	c;

	c.re = f->julia_re;
	c.im = f->julia_im;
	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			draw_julia_pixel(f, x, y, c);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
