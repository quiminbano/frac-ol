/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:39:43 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:25:45 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_aux(t_fractol *img, int button, float *zoom)
{
	if (button == 3)
	{
		*(zoom) = 1;
		ft_put_black(&(*img));
		if (img->flag == 0)
			ft_mandelbrot_zoom(&(*img), (*zoom));
		else
			ft_julia_move_zoom(&(*img), img->xm, img->ym, (*zoom));
	}
}

int	destroy(t_fractol *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->mlx_win);
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->img = NULL;
	exit(0);
}

int	ft_keydownevent(int keycode, t_fractol *img)
{
	if (keycode == 53)
		destroy(img);
	return (0);
}

int	ft_mousedownevent(int button, int x, int y, t_fractol *img)
{
	static float	zoom = 1;

	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom *= 1.1;
		if (button == 5 && zoom > 0.4)
			zoom /= 1.1;
		ft_put_black(&(*img));
		if (img->flag == 0)
			ft_mandelbrot_zoom(&(*img), zoom);
		else
			ft_julia_move_zoom(&(*img), img->xm, img->ym, zoom);
	}
	if (button == 2 && x <= 800 && y <= 600 && img->flag == 1)
	{
		img->signal = 1;
		ft_put_black(&(*img));
		img->xm = x;
		img->ym = y;
		ft_julia_move_zoom(&(*img), x, y, zoom);
	}
	if (button == 3)
		ft_mouse_aux(&(*img), button, &zoom);
	return (button);
}
