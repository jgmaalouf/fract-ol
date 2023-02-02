/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:35:32 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/11 14:40:56 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include <stdio.h>
# include <math.h>
# define WIDTH 900
# define HEIGHT 700
# define MAX_ITERATIONS 100

typedef struct s_axis
{
	int		width;
	int		height;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	mouse_x;
	double	mouse_y;
}			t_axis;

typedef struct s_fractal
{
	double	cr;
	double	ci;
	int		iterations;
	int		(*fractal_type)();
}			t_fractal;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_axis		axis;
	t_fractal	fract;
	int			i;
	int			j;
	int			k;
}				t_data;

// Color Functions
uint32_t	generate_colors(int iterations, int max_iterations, t_data *data);
int			change_color(t_data *data);

// Fractals Functions
int			mandelbrot(int x, int y, t_data *data);
int			julia(int x, int y, t_data *data);
int			burning_ship(int x, int y, t_data *data);
int			penis(int x, int y, t_data *data);
void		draw_fractal(t_data *data);

// Hooks Functions
void		hook(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);

// Utils Functions
void		*set_fractal(int argc, char **argv, t_data *data);
void		print_error(void);
void		print_help(void);

// Movement Functions
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

// Manipulation Functions
void		zoom_in_mouse(t_data *data);
void		zoom_out_mouse(t_data *data);
void		increase_iter(t_data *data);
void		decrease_iter(t_data *data);

#endif
