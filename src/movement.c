/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:53:47 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/06 18:28:57 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	move_up(t_data *data)
{
	double	diff;

	diff = data->axis.max_im - data->axis.min_im;
	data->axis.min_im -= diff / 50;
	data->axis.max_im -= diff / 50;
	draw_fractal(data);
}

void	move_down(t_data *data)
{
	double	diff;

	diff = data->axis.max_im - data->axis.min_im;
	data->axis.min_im += diff / 50;
	data->axis.max_im += diff / 50;
	draw_fractal(data);
}

void	move_left(t_data *data)
{
	double	diff;

	diff = data->axis.max_re - data->axis.min_re;
	data->axis.min_re -= diff / 50;
	data->axis.max_re -= diff / 50;
	draw_fractal(data);
}

void	move_right(t_data *data)
{
	double	diff;

	diff = data->axis.max_re - data->axis.min_re;
	data->axis.min_re += diff / 50;
	data->axis.max_re += diff / 50;
	draw_fractal(data);
}
