/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:21:53 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/11 13:29:35 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_data *data)
{
	int	x;
	int	y;
	int	iterations;

	y = 0;
	while (y < data->axis.height)
	{
		x = 0;
		while (x < data->axis.width)
		{
			iterations = data->fract.fractal_type(x, y, data);
			mlx_put_pixel(data->g_img, x, y,
				generate_colors(iterations, data->fract.iterations, data));
			x++;
		}
		y++;
	}
}

void	initialize_fractal(t_data *data, int argc, char **argv)
{
	data->i = 0;
	data->j = 1;
	data->k = 2;
	data->axis.width = WIDTH;
	data->axis.height = HEIGHT;
	data->axis.min_re = -2.0;
	data->axis.max_re = 1.0;
	data->axis.min_im = -1.02;
	data->axis.max_im = data->axis.min_im
		+ (data->axis.max_re - data->axis.min_re)
		* data->axis.height / data->axis.width;
	data->mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	data->g_img = mlx_new_image(data->mlx, data->axis.width, data->axis.height);
	data->fract.iterations = MAX_ITERATIONS;
	data->fract.fractal_type = set_fractal(argc, argv, data);
	if (data->fract.fractal_type == NULL)
		print_error();
}

void	my_resize_func(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = param;
	mlx_resize_image(data->g_img, width, height);
	data->axis.height = height;
	data->axis.width = width;
	data->axis.max_im = data->axis.min_im
		+ (data->axis.max_re - data->axis.min_re)
		* data->axis.height / data->axis.width;
	draw_fractal(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		print_error();
	initialize_fractal(&data, argc, argv);
	mlx_image_to_window(data.mlx, data.g_img, 0, 0);
	draw_fractal(&data);
	print_help();
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_scroll_hook(data.mlx, &my_scrollhook, &data);
	mlx_resize_hook(data.mlx, &my_resize_func, &data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.g_img);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
