/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:18 by corellan          #+#    #+#             */
/*   Updated: 2023/01/11 16:28:42 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_fractol *img)
{
	float		x;
	float		y;
	float		r;

	x = -399;
	y = 0;
	r = 399;
	img->img = mlx_new_image(img->mlx, 800, 800);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (x <= r)
	{
		y = sqrt((pow(r, 2)) - (pow(x, 2)));
		if (y > 799)
			break ;
		my_mlx_pixel_put(&(*img), (x + 400), (400 - y), fcolor(1, 255, 255, 255));
		my_mlx_pixel_put(&(*img), (x + 400), (400 + y), fcolor(1, 255, 255, 255));
		x += 0.01;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	main(void)
{
	t_fractol	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "Fract-ol");
	ft_draw(&img);
	mlx_mouse_hook(img.mlx_win, &ft_mouseevent, &img);
	mlx_key_hook(img.mlx_win, &ft_keyevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
