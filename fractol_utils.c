/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2023/01/11 16:36:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redraw(t_fractol *img, int color)
{
	float		x;
	float		y;
	float		r;

	x = -399;
	y = 0;
	r = 399;
	img->img = mlx_new_image(img->mlx, 800, 800);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (x <= r)
	{
		y = sqrt((pow(r, 2)) - (pow(x, 2)));
		if (y > 799)
			break ;
		my_mlx_pixel_put(&(*img), (x + 400), (400 - y), color);
		my_mlx_pixel_put(&(*img), (x + 400), (400 + y), color);
		x += 0.01;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
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
