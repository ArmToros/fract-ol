/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:24:21 by armtoros          #+#    #+#             */
/*   Updated: 2025/05/06 20:27:07 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	// MLX info
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	// View
	double	zoom;
	double	offset_x;
	double	offset_y;

	int		type;
	int		color_set;
	double	julia_re;
	double	julia_im;
	int		julia_mouse_lock;
}			t_fractol;

int			ft_strcmp(const char *s1, const char *s2);
void		draw_mandelbrot(t_fractol *f);
int			handle_key(int keycode, t_fractol *f);
int			close_window(t_fractol *f);
int			handle_mouse(int button, int x, int y, t_fractol *f);
int			handle_mouse_move(int x, int y, t_fractol *f);
void		start_julia(t_fractol *f, double x, double y);
void		my_mlx_pixel_put(t_fractol *f, int x, int y, int color);
int			get_color(int iter, int set);
void		draw_julia(t_fractol *f);
void		draw_mandelbrot(t_fractol *f);
int			loop_hook(void *param);

void		draw_burning_ship(t_fractol *f);
double		ft_atod(char *s);
int			ft_isjvalid(double i);
int			close_clean_window(t_fractol *f);
void		start(int check);
void		control_draw(t_fractol *f);
void		start_util(t_fractol *f, double z, double x, double y);

#endif
