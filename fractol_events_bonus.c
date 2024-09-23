/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:39:43 by corellan          #+#    #+#             */
/*   Updated: 2023/01/22 22:15:04 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_mouse_aux(t_fractol *img, int button, float *zoom)
{
	img->signal_zoom = 1;
	img->zoom_old = (*zoom);
	if (button == 4)
		(*zoom) *= 1.1;
	if (button == 5 && (*zoom) > 0.4)
		(*zoom) /= 1.1;
	ft_put_black(&(*img));
	(*img->zoom) = (*zoom);
	ft_check_flags_event(&(*img), *(img->zoom));
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
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
	{
		if (keycode == 126)
			*(img->ud) -= 0.1;
		if (keycode == 125)
			*(img->ud) += 0.1;
		if (keycode == 123)
			*(img->lr) -= 0.1;
		if (keycode == 124)
			*(img->lr) += 0.1;
		img->signal_key = 1;
		ft_put_black(&(*img));
		ft_check_flags_event(&(*img), *(img->zoom));
	}
	if (keycode == 1 || keycode == 13)
		ft_color_changer(keycode, &(*img));
	if (keycode == 53)
		destroy(&(*img));
	return (0);
}

int	ft_mousedownevent(int button, int x, int y, t_fractol *img)
{
	img->m_x = x;
	img->m_y = y;
	if ((button == 4 || button == 5) && (x <= 800 && x >= 0) && \
		(y >= 0 && y <= 600))
		ft_mouse_aux(&(*img), button, &(*(img->zoom)));
	if (button == 3)
	{
		*(img->zoom) = 1;
		*(img->lr) = 0;
		*(img->ud) = 0;
		ft_put_black(&(*img));
		ft_check_flags_event(&(*img), *(img->zoom));
	}
	if (button == 2 && (x <= 800 && x >= 0) && (y >= 0 && y <= 600) && \
		((img->flag == 1) || (img->flag == 3)))
	{
		img->signal = 1;
		ft_put_black(&(*img));
		img->xm = x;
		img->ym = y;
		ft_check_flags_event(&(*img), *(img->zoom));
	}
	return (button);
}
