/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2023/01/16 17:23:14 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_move(t_fractol *img, int xm, int ym)
{
	float		x;
	float		y;
	t_complex	n;

	x = 0;
	y = 0;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (y <= 599)
	{
		while (x <= 799)
		{
			n.x_z = ((x / 200) - 2);
			n.y_z = ((y / 200) - 1.5);
			n.x_c = (((float)xm / 200) - 2);
			n.y_c = (((float)ym / 200) - 1.5);
			if (ft_iter(&n, 2, 100) == 1)
				my_mlx_pixel_put(&(*img), x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0; 
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	ft_iter(t_complex *n, float limit, int iter)
{
	int	i;

	i = 0;
	while ((n->x_z >= (limit * -1) && n->x_z <= limit) && \
		(n->y_z >= (limit * -1) && n->y_z <= limit) && (i < iter))
	{
		n->x = ((n->x_z * n->x_z) - (n->y_z * n->y_z));
		n->y = (2 * n->x_z * n->y_z);
		n->x += n->x_c;
		n->y += n->y_c;
		n->x_z = n->x;
		n->y_z = n->y;
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
