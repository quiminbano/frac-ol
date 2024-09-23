/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_colorcont_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:52:46 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:34 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_color5(t_fractol *img)
{
	img->color1 = fcolor(20, 0, 0, 204);
	img->color2 = fcolor(20, 255, 51, 51);
	img->color3 = fcolor(10, 0, 204, 204);
	img->color4 = fcolor(20, 204, 0, 204);
	img->color5 = fcolor(0, 0, 204, 0);
	img->color6 = fcolor(100, 153, 51, 255);
	img->color7 = fcolor(20, 73, 153, 0);
	img->color8 = fcolor(20, 0, 0, 153);
	img->color9 = fcolor(0, 255, 255, 0);
	img->color10 = fcolor(20, 0, 102, 204);
	img->color11 = fcolor(0, 255, 128, 0);
	img->background = fcolor(0, 255, 179, 0);
}

void	ft_put_color(t_fractol *img, t_complex *n)
{
	if (n->i == 3)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color1);
	if (n->i >= 4)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color2);
	if (n->i == 5)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color3);
	if (n->i >= 6 && n->i < 8)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color4);
	if (n->i >= 8 && n->i < 10)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color5);
	if (n->i >= 10 && n->i < 15)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color6);
	if (n->i >= 15 && n->i < 20)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color7);
	if (n->i >= 20 && n->i < 30)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color8);
	if (n->i >= 30 && n->i < 40)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color9);
	if (n->i >= 40 && n->i < 200)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color10);
	if (n->i == 200)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->color11);
	if (n->i >= 0 && n->i < 3 && img->background > 0)
		my_mlx_pixel_put(&(*img), n->r, n->im, img->background);
}
