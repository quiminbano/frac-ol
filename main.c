/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:18 by corellan          #+#    #+#             */
/*   Updated: 2023/01/15 23:44:58 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_init(t_fractol *img)
{
	float		x;
	float		y;
	t_complex	n;

	x = 0;
	y = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (y <= 599)
	{
		while (x <= 799)
		{
			n.x_i = (((3 * x) / 800) - 2);
			n.y_i = ((y / 300) - 1);
			if (ft_iter_julia(&n, n.x_i, n.y_i, 100) == 1)
				my_mlx_pixel_put(&(*img), x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_mandelbrot_init(t_fractol *img)
{
	float		x;
	float		y;
	t_complex	n;

	x = 0;
	y = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (y <= 599)
	{
		while (x <= 799)
		{
			n.x_i = (((3 * x) / 800) - 2);
			n.y_i = ((y / 300) - 1);
			if (ft_iter_mandelbrot(&n, n.x_i, n.y_i, 100) == 1)
				my_mlx_pixel_put(&(*img), x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_checker(t_fractol *img, char **av)
{
	if ((ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0))
		img->flag = 0;
	else
		img->flag = 1;
}

int	main(int ac, char **av)
{
	t_fractol	img;

	if (ac != 2)
	{
		ft_printf("Fractol: Usage ./fractol mandelbrot or ./fractol julia\n");
		return (1);
	}
	if (((ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) != 0) && \
		(ft_strncmp(av[1], "julia", ft_strlen(av[1])) != 0)))
	{
		ft_printf("Fractol: Usage ./fractol mandelbrot or ./fractol julia\n");
		return (1);
	}
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 600, "Fract-ol");
	ft_checker(&img, av);
	if (img.flag == 0)
		ft_mandelbrot_init(&img);
	else
		ft_julia_init(&img);
	mlx_mouse_hook(img.mlx_win, &ft_mouseevent, &img);
	mlx_key_hook(img.mlx_win, &ft_keyevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
