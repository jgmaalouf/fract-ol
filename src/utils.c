/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:23:37 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/10/14 12:32:07 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	*set_fractal(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (ft_strncmp("Mandelbrot", argv[1], 11) == 0)
			return (&mandelbrot);
		if (ft_strncmp("Burning Ship", argv[1], 11) == 0)
			return (&burning_ship);
		if (ft_strncmp("Penis", argv[1], 11) == 0)
			return (&penis);
	}
	if (argc == 3)
	{
		if (ft_strncmp("Burning", argv[1], 8) == 0
			&& ft_strncmp("Ship", argv[2], 5) == 0)
			return (&burning_ship);
	}
	if (argc == 4 && ft_isnum(argv[2]) && ft_isnum(argv[3]))
	{
		if (ft_strncmp("Julia", argv[1], 6) == 0)
		{
			data->fract.cr = ft_atof(argv[2]);
			data->fract.ci = ft_atof(argv[3]);
			return (&julia);
		}
	}
	return (NULL);
}

void	print_error(void)
{
	write(2, "\033[0;31m", 8);
	write(2, "Input error\n\n", 13);
	write(2, "\033[33;1m", 8);
	write(1, "You have to specify what fractal you want rendered.\n", 53);
	write(1, "\tFractals you can render are:\n", 31);
	write(1, "\033[1m", 5);
	write(1, "\033[37;1m", 8);
	write(1, "\t\t- Mandelbrot\n", 16);
	write(1, "\t\t- Julia (real) (imaginary) | e.g. -0.744 -0.148\n", 51);
	write(1, "\t\t- Burning Ship\n", 18);
	write(1, "\t\t- Penis\n", 11);
	exit(EXIT_FAILURE);
}

void	print_help(void)
{
	write(1, "\t\t******************************************************\n", 58);
	write(1, "\t\t* Use the arrow keys to move around                  *\n", 58);
	write(1, "\t\t* Scroll with the mouse to zoom in and out           *\n", 58);
	write(1, "\t\t* Use the mouse left click to change colors          *\n", 58);
	write(1, "\t\t* Use the + and - on the numpad to change iterations *\n", 58);
	write(1, "\t\t* Use the ESC key to quit the program                *\n", 58);
	write(1, "\t\t******************************************************\n", 58);
}
