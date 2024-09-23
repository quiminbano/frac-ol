/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:48:29 by corellan          #+#    #+#             */
/*   Updated: 2023/01/25 16:49:42 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_checker_coord(t_fractol *img, t_complex *n, float xm, float ym)
{
	n->x_c = img->i_x;
	n->y_c = img->i_y;
	if (img->signal == 1)
	{
		n->x_c = (((float)xm / 200) - 2);
		n->y_c = (((float)ym / 200) - 1.5);
	}
}

void	ft_mandelbrot_zoom(t_fractol *img, float zoom)
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
			n.x_c = ((n.r / (200 * zoom)) - (2 / zoom));
			n.y_c = ((n.im / (200 * zoom)) - (1.5 / zoom));
			n.x_z = 0;
			n.y_z = 0;
			ft_iter(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_put_black(t_fractol *img)
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
			my_mlx_pixel_put(&(*img), n.r, n.im, 0x00000000);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_julia_move_zoom(t_fractol *img, int xm, int ym, float zoom)
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
			n.x_z = ((n.r / (200 * zoom)) - (2 / zoom));
			n.y_z = ((n.im / (200 * zoom)) - (1.5 / zoom));
			ft_checker_coord(&(*img), &n, xm, ym);
			ft_iter(img, &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_iter(t_fractol *img, t_complex *n)
{
	n->i = 0;
	while (n->i < 200)
	{
		n->x = ((n->x_z * n->x_z) - (n->y_z * n->y_z));
		n->y = (2 * n->x_z * n->y_z);
		n->x += n->x_c;
		n->y += n->y_c;
		n->x_z = n->x;
		n->y_z = n->y;
		if (((n->x * n->x) + (n->y * n->y)) > 4)
			break ;
		(n->i)++;
	}
	if (n->i == 200)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(0, 255, 255, 255));
	if (n->i >= 20 && n->i < 200)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(0, 0, 0, 0));
	if (n->i >= 4 && n->i < 20)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(50, 255, 255, 255));
	if (n->i == 3)
		my_mlx_pixel_put(&(*img), n->r, n->im, fcolor(80, 255, 255, 255));
}
