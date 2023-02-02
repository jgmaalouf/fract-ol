/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:43 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/11 08:30:37 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		change_color(data);
		draw_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD))
		increase_iter(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_SUBTRACT))
		decrease_iter(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_right(data);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	xdelta = 0;
	if (ydelta > 0)
	{
		zoom_in_mouse(data);
		draw_fractal(data);
	}
	else if (ydelta < 0)
	{
		zoom_out_mouse(data);
		draw_fractal(data);
	}
}
