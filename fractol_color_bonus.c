/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:23:49 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:31 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_color4(t_fractol *img)
{
	img->color1 = fcolor(80, 255, 255, 0);
	img->color2 = fcolor(60, 255, 255, 0);
	img->color3 = fcolor(10, 255, 255, 0);
	img->color4 = fcolor(20, 255, 255, 0);
	img->color5 = fcolor(40, 255, 255, 0);
	img->color6 = fcolor(100, 255, 255, 0);
	img->color7 = fcolor(20, 255, 255, 0);
	img->color8 = fcolor(40, 255, 255, 0);
	img->color9 = fcolor(10, 255, 255, 0);
	img->color10 = fcolor(40, 255, 255, 0);
	img->color11 = fcolor(0, 255, 255, 0);
	img->background = fcolor(0, 0, 0, 0);
}

static void	ft_color3(t_fractol *img)
{
	img->color1 = fcolor(80, 0, 255, 255);
	img->color2 = fcolor(60, 0, 255, 255);
	img->color3 = fcolor(10, 0, 255, 255);
	img->color4 = fcolor(20, 0, 255, 255);
	img->color5 = fcolor(40, 0, 255, 255);
	img->color6 = fcolor(0, 0, 0, 0);
	img->color7 = fcolor(20, 0, 255, 255);
	img->color8 = fcolor(40, 0, 255, 255);
	img->color9 = fcolor(10, 0, 255, 255);
	img->color10 = fcolor(40, 0, 255, 255);
	img->color11 = fcolor(0, 0, 255, 255);
	img->background = fcolor(0, 0, 0, 0);
}

static void	ft_color2(t_fractol *img)
{
	img->color1 = fcolor(80, 255, 0, 255);
	img->color2 = fcolor(60, 255, 0, 255);
	img->color3 = fcolor(10, 255, 0, 255);
	img->color4 = fcolor(20, 255, 0, 255);
	img->color5 = fcolor(40, 255, 0, 255);
	img->color6 = fcolor(0, 0, 0, 0);
	img->color7 = fcolor(20, 255, 0, 255);
	img->color8 = fcolor(40, 255, 0, 255);
	img->color9 = fcolor(10, 255, 0, 255);
	img->color10 = fcolor(40, 255, 0, 255);
	img->color11 = fcolor(0, 255, 0, 255);
	img->background = fcolor(0, 0, 0, 0);
}

void	ft_color1(t_fractol *img)
{
	img->color1 = fcolor(80, 255, 255, 255);
	img->color2 = fcolor(60, 255, 255, 255);
	img->color3 = fcolor(10, 255, 255, 255);
	img->color4 = fcolor(20, 255, 255, 255);
	img->color5 = fcolor(40, 255, 255, 255);
	img->color6 = fcolor(0, 0, 0, 0);
	img->color7 = fcolor(20, 255, 255, 255);
	img->color8 = fcolor(40, 255, 255, 255);
	img->color9 = fcolor(10, 255, 255, 255);
	img->color10 = fcolor(40, 255, 255, 255);
	img->color11 = fcolor(0, 255, 255, 255);
	img->background = fcolor(0, 0, 0, 0);
}

void	ft_color_changer(int keycode, t_fractol *img)
{
	static int	i = 0;

	if (keycode == 1)
		i -= 1;
	if (keycode == 13)
		i += 1;
	if (i == 5)
		i = 0;
	if (i == -1)
		i = 4;
	if (i == 0)
		ft_color1(&(*img));
	if (i == 1)
		ft_color2(&(*img));
	if (i == 2)
		ft_color3(&(*img));
	if (i == 3)
		ft_color4(&(*img));
	if (i == 4)
		ft_color5(&(*img));
	ft_put_black(&(*img));
	ft_check_flags_event(&(*img), *(img->zoom));
}
