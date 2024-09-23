/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_iter_mult(t_fractol *img, t_complex *n)
{
	n->i = 0;
	while (n->i < 200)
	{
		n->x = ((n->xz * n->xz * n->xz) - (3 * (n->xz) * (n->yz * n->yz)));
		n->y = (3 * n->xz * n->xz * n->yz) - (n->yz * n->yz * n->yz);
		n->x += n->xc;
		n->y += n->yc;
		n->xz = n->x;
		n->yz = n->y;
		if (((n->x * n->x) + (n->y * n->y)) > 2.8)
			break ;
		(n->i)++;
	}
	ft_put_color(&(*img), &(*n));
}

void	ft_iter(t_fractol *img, t_complex *n)
{
	n->i = 0;
	while (n->i < 200)
	{
		n->x = ((n->xz * n->xz) - (n->yz * n->yz));
		n->y = (2 * n->xz * n->yz);
		n->x += n->xc;
		n->y += n->yc;
		n->xz = n->x;
		n->yz = n->y;
		if (((n->x * n->x) + (n->y * n->y)) > 4)
			break ;
		(n->i)++;
	}
	ft_put_color(&(*img), &(*n));
}

void	ft_float(t_fractol *img)
{
	static float	ud = 0;
	static float	lr = 0;
	static float	zoom = 1;

	img->zoom = &zoom;
	img->ud = &ud;
	img->lr = &lr;
}

void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
