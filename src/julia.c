/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:29:26 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 13:37:25 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *f)
{
	int		x, y, i;
	t_complex z, c;

	c.re = f->julia_re; // Julia constant re
	c.im = f->julia_im; // Julia constant im

	// Clear the previous image (if necessary)
	mlx_clear_window(f->mlx, f->win); // Clear the window before redrawing

	// Loop over the pixels in the window
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			// Map pixel (x, y) to a complex number
			z.re = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * f->zoom + f->offset_x;
			z.im = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * f->zoom + f->offset_y;

			// Iterate to check if the point escapes
			i = 0;
			while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
			{
				double temp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = temp;
				i++;
			}

			// Set color based on iteration count
			my_mlx_pixel_put(f, x, y, get_color(i, f->color_set));
		}
	}

	// Display the updated image
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}


