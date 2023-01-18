/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2023/01/17 19:32:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_move(t_fractol *img, int xm, int ym)
{
	t_complex	n;

	n.r = 0;
	n.im = 0;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (n.im <= 599)
	{
		while (n.r <= 799)
		{
			n.x_z = ((n.r / 200) - 2);
			n.y_z = ((n.im / 200) - 1.5);
			n.x_c = (((float)xm / 200) - 2);
			n.y_c = (((float)ym / 200) - 1.5);
			ft_iter(img, &n, 2, 100);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0; 
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_iter(t_fractol *img, t_complex *n, float limit, int iter)
{
	n->i = 0;
	while ((n->x_z >= (limit * -1) && n->x_z <= limit) && \
		(n->y_z >= (limit * -1) && n->y_z <= limit) && (n->i < iter))
	{
		n->x = ((n->x_z * n->x_z) - (n->y_z * n->y_z));
		n->y = (2 * n->x_z * n->y_z);
		n->x += n->x_c;
		n->y += n->y_c;
		n->x_z = n->x;
		n->y_z = n->y;
		(n->i)++;
	}
	if (n->i == iter)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(0, 255, 255, 255));
	if (n->i >= 10 && n->i <= 15)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(0, 34, 0, 255));
	if (n->i > 20 && n->i <= 25)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(0, 0, 255, 255));
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
