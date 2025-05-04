/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:25:57 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/03 19:31:22 by armtoros         ###   ########.fr       */
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
	double t;
	
	if (iter == MAX_ITER)
		return (0x000000); // Black for points inside the set
	t = iter / (double)MAX_ITER;
	if (set == 1) // Red gradient
	{
		int red = (int)(255 * t);
		return (red << 16);
	}
	else if (set == 2) // Green gradient
	{
		int green = (int)(255 * t);
		return (green << 8);
	}
	else // Default RGB blend
	{
		int red = (int)(100 * t);
		int green = (int)(180 * t);
		int blue = (int)(255 * t);
		return ((red << 16) | (green << 8) | blue);
	}
}


int ft_isJvalid(double i)
{
	if (i <= 2.0 && i >= -2.0)
		return (1);
	return(0);
}
