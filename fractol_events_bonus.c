/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:39:43 by corellan          #+#    #+#             */
/*   Updated: 2023/01/19 23:21:42 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_aux(t_fractol *img, int button, float *zoom)
{
	if (button == 4)
		(*zoom) += 0.1;
	if (button == 5 && (*zoom) > 0.4)
		(*zoom) -= 0.1;
	ft_put_black(&(*img));
		img->zoom = (*zoom);
	if (img->flag == 0)
		ft_mandelbrot_zoom(&(*img), (*zoom));
	else
		ft_julia_move_zoom(&(*img), img->xm, img->ym, (*zoom));
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
	static float	ud = 0;
	static float	lr = 0;

	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		if (keycode == 126)
			ud -= 0.1;
		if (keycode == 125)
			ud += 0.1;
		if (keycode == 123)
			lr -= 0.1;
		if (keycode == 124)
			lr += 0.1;
		img->signal_key = 1;
		img->ud = ud;
		img->lr = lr;
		ft_put_black(&(*img));
		if (img->flag == 0)
			ft_mandelbrot_zoom(&(*img), img->zoom);
		else
			ft_julia_move_zoom(&(*img), img->xm, img->ym, img->zoom);
	}
	if (keycode == 53)
		destroy(img);
	return (0);
}

int	ft_mousedownevent(int button, int x, int y, t_fractol *img)
{
	static float	zoom = 1;

	if (button == 4 || button == 5)
		ft_mouse_aux(&(*img), button, &zoom);
	if (button == 2 && x <= 800 && y <= 600 && img->flag == 1)
	{
		img->signal = 1;
		ft_put_black(&(*img));
		img->xm = x;
		img->ym = y;
		ft_julia_move_zoom(&(*img), x, y, zoom);
	}
	return (button);
}

void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
