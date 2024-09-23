/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilscont_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:50:32 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:55 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

size_t	ft_argument_checker(char *str)
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

void	ft_check_flags_event(t_fractol *img, float zoom)
{
	if (img->flag == 0)
		man_z(&(*img), zoom, &ft_iter);
	else if (img->flag == 1)
		jul_z(&(*img), zoom, &ft_iter);
	else if (img->flag == 2)
		man_z(&(*img), zoom, &ft_iter_mult);
	else
		jul_z(&(*img), zoom, &ft_iter_mult);
}
