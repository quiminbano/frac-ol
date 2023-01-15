/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:39:43 by corellan          #+#    #+#             */
/*   Updated: 2023/01/15 23:10:09 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_fractol *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}

int	ft_mouseevent(int button, int x, int y, t_fractol *img)
{
	if (button == 1 && x <= 800 && y <= 600)
		ft_printf("hello\n");
	if (button == 2 && x <= 800 && y <= 600)
		ft_printf("hello\n");
	ft_printf("%d\n", img->bits_per_pixel);
	return (button);
}

int	ft_keyevent(int keycode)
{
	return (keycode);
}

void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
