/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:18:45 by corellan          #+#    #+#             */
/*   Updated: 2023/01/24 18:19:45 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_i(t_fractol *img, char **av, void (*f)(t_fractol *, t_complex *))
{
	t_complex	n;

	n.r = 0;
	n.im = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (n.im <= 599)
	{
		while (n.r <= 799)
		{
			n.xz = ((n.r / 200) - 2);
			n.yz = ((n.im / -200) + 1.5);
			n.xc = ft_atof(av[2]);
			n.yc = ft_atof(av[3]);
			img->i_x = n.xc;
			img->i_y = n.yc;
			(*f)(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	mandelbrot_i(t_fractol *img, void (*f)(t_fractol *, t_complex *))
{
	t_complex	n;

	n.r = 0;
	n.im = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (n.im <= 599)
	{
		while (n.r <= 799)
		{
			n.xc = ((n.r / 200) - 2);
			n.yc = ((n.im / -200) + 1.5);
			n.xz = 0;
			n.yz = 0;
			(*f)(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
