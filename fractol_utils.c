/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:51 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_atof_aux(char *str, double number, int i, double sig)
{
	int		j;
	int		k;
	double	dec;

	j = i - 1;
	k = 0;
	dec = 10;
	while (str[k] != '.' && str[k] != '\0')
		k++;
	while (str[i] <= 57 && str[i] >= 48)
	{
		if (k != j)
			break ;
		number += ((str[i] - 48) / (dec));
		dec *= 10;
		i++;
	}
	return (number * sig);
}

double	ft_atof(char *str)
{
	double	number;
	int		i;
	double	sig;

	i = 0;
	number = 0;
	sig = 1;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		number *= 10;
		number += (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	return (ft_atof_aux(str, number, i, sig));
}

int	fcolor(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	int	tr;
	int	re;
	int	gr;
	int	bl;

	tr = ((255 * t) / 100);
	tr = (unsigned char)tr;
	re = (int)r;
	gr = (int)g;
	bl = (int)b;
	return (tr << 24 | re << 16 | gr << 8 | bl);
}

void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
