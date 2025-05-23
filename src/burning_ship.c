/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:32 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 15:03:35 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	util(t_fractol *f, int x, int y)
{
	int			iter;
	double		tmp;
	t_complex	c;
	t_complex	z;

	while (x < WIDTH)
	{
		c.re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
		c.im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;
		z.re = 0;
		z.im = 0;
		iter = 0;
		while ((z.re * z.re + z.im * z.im <= 4.0) && (iter < MAX_ITER))
		{
			tmp = z.re * z.re - z.im * z.im + c.re;
			z.im = fabs(2.0 * z.re * z.im) + c.im;
			z.re = tmp;
			iter++;
		}
		my_mlx_pixel_put(f, x, y, get_color(iter, f->color_set));
		x++;
	}
}

void	draw_burning_ship(t_fractol *f)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		util(f, 0, y);
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
