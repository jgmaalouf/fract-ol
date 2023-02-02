/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:28:47 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/12/21 17:55:03 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in_mouse(t_data *data)
{
	int32_t	x;
	int32_t	y;
	double	x_coord;
	double	y_coord;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	printf("%d\n", x);
	printf("%d\n", y);
	x_coord = data->axis.min_re + (double)x * (data->axis.max_re - data->axis.min_re) / data->axis.width;
	y_coord = data->axis.min_im + (double)y * (data->axis.max_im - data->axis.min_im) / data->axis.height;
	printf("%f\n", x_coord);
	printf("%f\n", y_coord);
	data->axis.min_re = (data->axis.min_re / 1.1) + x_coord - (x_coord / 1.1);
	data->axis.max_re = (data->axis.max_re / 1.1) + x_coord - (x_coord / 1.1);
	data->axis.min_im = (data->axis.min_im / 1.1) + y_coord - (y_coord / 1.1);
	data->axis.max_im = (data->axis.max_im / 1.1) + y_coord - (y_coord / 1.1);
}

void	zoom_out_mouse(t_data *data)
{
	int32_t	x;
	int32_t	y;
	double	x_coord;
	double	y_coord;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	x_coord = data->axis.min_re + (double)x
		* (data->axis.max_re - data->axis.min_re) / data->axis.width;
	y_coord = data->axis.min_im + (double)y
		* (data->axis.max_im - data->axis.min_im) / data->axis.height;
	data->axis.min_re = (data->axis.min_re * 1.1) + x_coord - (x_coord * 1.1);
	data->axis.max_re = (data->axis.max_re * 1.1) + x_coord - (x_coord * 1.1);
	data->axis.min_im = (data->axis.min_im * 1.1) + y_coord - (y_coord * 1.1);
	data->axis.max_im = (data->axis.max_im * 1.1) + y_coord - (y_coord * 1.1);
}

void	increase_iter(t_data *data)
{
	data->fract.iterations += 10;
	draw_fractal(data);
}

void	decrease_iter(t_data *data)
{
	data->fract.iterations -= 10;
	draw_fractal(data);
}
