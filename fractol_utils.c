/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2023/01/15 23:53:37 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iter_julia(t_complex *n, float x_c, float y_c, int iter)
{
	int	i;

	i = 0;
	n->x_i = (0.8 * -1);
	n->y_i = (0.156);
	while ((x_c >= -2 && x_c <= 2) && (y_c >= -2 && y_c <= 2) && \
		(i < iter))
	{
		n->x = ((x_c * x_c) - (y_c * y_c));
		n->y = (2 * x_c * y_c);
		n->x += n->x_i;
		n->y += n->y_i;
		x_c = n->x;
		y_c = n->y;
		i++;
	}
	if (i == iter)
		return (1);
	else
		return (0);	
}

int	ft_iter_mandelbrot(t_complex *n, float x_init, float y_init, int iter)
{
	int	i;

	i = 0;
	n->x_c = 0;
	n->y_c = 0;
	while ((n->x_c >= -8 && n->x_c <= 8) && (n->y_c >= -8 && n->y_c <= 8) && \
		(i < iter))
	{
		n->x = ((n->x_c * n->x_c) - (n->y_c * n->y_c));
		n->y = (2 * n->x_c * n->y_c);
		n->x += x_init;
		n->y += y_init;
		n->x_c = n->x;
		n->y_c = n->y;
		i++;
	}
	if (i == iter)
		return (1);
	else
		return (0);	
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
