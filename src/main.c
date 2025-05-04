/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:25:19 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/04 13:40:16 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_error(void)
{
	write(1, "Usage: ./fractol mandelbrot | julia x[-2;2] y[-2;2] | 'burning ship'\n", 70);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
		write_error();
	else if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			start(0);
		else if (!ft_strcmp(argv[1], "burning ship"))
			start(1);
		else
			write_error();
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia")
		&& ft_isJvalid(ft_atod(argv[2])) && ft_isJvalid(ft_atod(argv[3])))
		start_julia(&f, ft_atod(argv[2]), ft_atod(argv[3]));
	else
		write_error();
	return (0);
}
