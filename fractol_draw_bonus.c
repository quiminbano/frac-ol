/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:48:29 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:36 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_checker_coord(t_fractol *img, t_complex *n, float zoom)
{
	if (n->im == 0 && n->r == 0 && img->signal_zoom == 1)
	{
		img->x1 = ((img->m_x / (200 * img->zoom_old)) - \
			(((2 + *(img->lr)) / img->zoom_old)));
		img->x2 = ((img->m_x / (200 * zoom)) - (((2 + *(img->lr)) / zoom)));
		img->y1 = ((img->m_y / (-200 * img->zoom_old)) + \
			(((1.5 + *(img->ud)) / img->zoom_old)));
		img->y2 = ((img->m_y / (-200 * zoom)) + (((1.5 + *(img->ud)) / zoom)));
		*(img->lr) += ((img->x2 - img->x1) * zoom);
		*(img->ud) -= ((img->y2 - img->y1) * zoom);
	}
	n->xz = ((n->r / (200 * zoom)) - (((2 + *(img->lr)) / zoom)));
	n->yz = (((n->im) / (-200 * zoom)) + (((1.5 + *(img->ud)) / zoom)));
	n->xc = img->i_x;
	n->yc = img->i_y;
	if (img->signal == 1)
	{
		n->xc = (((float)img->xm / 200) - 2);
		n->yc = (((float)img->ym / -200) + 1.5);
	}
}

void	jul_z(t_fractol *img, float zoom, void (*f)(t_fractol *, t_complex *))
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
			ft_checker_coord(&(*img), &n, zoom);
			(*f)(img, &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	img->signal_zoom = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

static void	ft_checker_mandel(t_fractol *img, t_complex *n, float zoom)
{
	if (n->im == 0 && n->r == 0 && img->signal_zoom == 1)
	{
		img->x1 = ((img->m_x / (200 * img->zoom_old)) - \
			(((2 + *(img->lr)) / img->zoom_old)));
		img->x2 = ((img->m_x / (200 * zoom)) - (((2 + *(img->lr)) / zoom)));
		img->y1 = ((img->m_y / (-200 * img->zoom_old)) + \
			(((1.5 + *(img->ud)) / img->zoom_old)));
		img->y2 = ((img->m_y / (-200 * zoom)) + (((1.5 + *(img->ud)) / zoom)));
		*(img->lr) += ((img->x2 - img->x1) * zoom);
		*(img->ud) -= ((img->y2 - img->y1) * zoom);
	}
	n->xc = ((n->r / (200 * zoom)) - ((2 + *(img->lr)) / zoom));
	n->yc = ((n->im / (-200 * zoom)) + ((1.5 + *(img->ud)) / zoom));
}

void	man_z(t_fractol *img, float zoom, void (*f)(t_fractol *, t_complex *))
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
			ft_checker_mandel(&(*img), &n, zoom);
			n.xz = 0;
			n.yz = 0;
			(*f)(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	img->signal_zoom = 0;
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
