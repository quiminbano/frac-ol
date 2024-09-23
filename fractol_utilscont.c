/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilscont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:53:11 by corellan          #+#    #+#             */
/*   Updated: 2023/01/24 18:23:52 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_argument_checker(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while ((str[i] <= 57 && str[i] >= 48) || (str[i] == '.'))
	{
		if (str[i] == '.')
			j++;
		if (str[0] == '.' || (j >= 2))
			break ;
		i++;
	}
	return (i);
}

int	ft_checker_julia(t_fractol *img, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 12) == 0)
		return (0);
	if (ft_argument_checker(av[2]) < ft_strlen(av[2]))
		return (-1);
	if (ft_argument_checker(av[3]) < ft_strlen(av[3]))
		return (-1);
	img->i_x = ft_atof(av[2]);
	img->i_y = ft_atof(av[3]);
	if ((ft_strncmp(av[1], "julia", 6) == 0) && ((img->i_x > 2 || \
		img->i_x < -2) || (img->i_y > 2 || img->i_y < -2)))
		return (-1);
	return (0);
}
