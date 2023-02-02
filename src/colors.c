/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:51:56 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/11 08:52:53 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

uint32_t	to_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((uint32_t)(red << 24 | green << 16 | blue << 8 | 0xFF));
}

uint32_t	generate_colors(int iterations, int max_iterations, t_data *data)
{
	double	ratio;
	double	ratio_reciprocal;
	uint8_t	colors[3];

	ratio = (double)iterations / (double)max_iterations;
	ratio_reciprocal = 1.0 - ratio;
	colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
	colors[1] = 15 * (ratio * ratio)
		* (ratio_reciprocal * ratio_reciprocal) * 255;
	colors[2] = 9 * ratio
		* (ratio_reciprocal * ratio_reciprocal * ratio_reciprocal) * 255;
	return (to_rgb(colors[data->i], colors[data->j], colors[data->k]));
}

int	change_color(t_data *data)
{
	if (data->i < 2)
	{
		if (data->j < 2)
		{
			if (data->k < 2)
				return (data->k++);
			return (data->j++);
		}
		data->j = 0;
		data->k = 0;
		return (data->i++);
	}
	data->i = 0;
	return (1);
}
