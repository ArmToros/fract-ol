/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:53 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 15:04:55 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int set)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iter == MAX_ITER)
		return (0x000000);
	t = iter / (double)MAX_ITER;
	if (set == 1)
	{
		red = (int)(255 * t);
		return (red << 16);
	}
	else if (set == 2)
	{
		green = (int)(255 * t);
		return (green << 8);
	}
	else
	{
		red = (int)(100 * t);
		green = (int)(180 * t);
		blue = (int)(255 * t);
		return ((red << 16) | (green << 8) | blue);
	}
}

int	ft_isjvalid(double i)
{
	if (i <= 2.0 && i >= -2.0)
		return (1);
	return (0);
}
