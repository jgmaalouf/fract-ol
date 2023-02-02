/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:17:35 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/12/21 17:56:36 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(int x, int y, t_data *data)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	i = 0;
	zr = 0;
	zi = 0;
	data->fract.cr = data->axis.min_re + (double)x * (data->axis.max_re - data->axis.min_re) / data->axis.width;
	data->fract.ci = data->axis.min_im + (double)y * (data->axis.max_im - data->axis.min_im) / data->axis.height;
	while (i < data->fract.iterations)
	{
		if (zr * zr + zi * zi > 4.0)
			return (i);
		tmp = zr * zr - zi * zi + data->fract.cr;
		zi = 2 * zr * zi + data->fract.ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	julia(int x, int y, t_data *data)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	i = 0;
	zr = data->axis.min_re + (double)x
		* (data->axis.max_re - data->axis.min_re) / data->axis.width;
	zi = data->axis.min_im + (double)y
		* (data->axis.max_im - data->axis.min_im) / data->axis.height;
	while (i < data->fract.iterations)
	{
		if (zr * zr + zi * zi > 4.0)
			return (i);
		tmp = zr * zr - zi * zi + data->fract.cr;
		zi = 2 * zr * zi + data->fract.ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	burning_ship(int x, int y, t_data *data)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	i = 0;
	zr = 0;
	zi = 0;
	data->fract.cr = data->axis.min_re + (double)x
		* (data->axis.max_re - data->axis.min_re) / data->axis.width;
	data->fract.ci = data->axis.min_im + (double)y
		* (data->axis.max_im - data->axis.min_im) / data->axis.height;
	while (i < data->fract.iterations)
	{
		if (zr * zr + zi * zi > 4.0)
			return (i);
		tmp = fabs(zr * zr - zi * zi + data->fract.cr);
		zi = fabs(2 * zr * zi + data->fract.ci);
		zr = tmp;
		i++;
	}
	return (i);
}

int	penis(int x, int y, t_data *data)
{
	int		i;
	double	tmp;
	double	zr;
	double	zi;

	i = 0;
	zr = 0;
	zi = 0;
	data->fract.ci = data->axis.min_re + (double)x
		* (data->axis.max_re - data->axis.min_re) / data->axis.width;
	data->fract.cr = data->axis.min_im + (double)y
		* (data->axis.max_im - data->axis.min_im) / data->axis.height;
	while (i < data->fract.iterations)
	{
		if (zr * zr + zi * zi > 4.0)
			return (i);
		tmp = fabs(zr * zr - zi * zi + data->fract.cr);
		zi = 2 * zr * zi + data->fract.ci;
		zr = tmp;
		i++;
	}
	return (i);
}
