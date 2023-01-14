/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:18 by corellan          #+#    #+#             */
/*   Updated: 2023/01/14 18:29:50 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iter(t_complex *n, float x_init, float y_init, int iter)
{
	int	i;

	i = 0;
	n->x_c = 0;
	n->y_c = 0;
	while ((n->x_c > -2 && n->x_c < 2) && (n->y_c > -1 && n->y_c < 1) && \
		(i < iter))
	{
		n->x = ((pow(n->x_c, 2)) - (pow(n->y_c, 2)));
		n->y = (2 * n->x_c * n->y_c);
		n->x += x_init;
		n->y += y_init;
		n->x_c = n->x;
		n->y_c = n->y;
		i++;
	}
	if (i == iter)
		return (1);
	else
		return (0);	
}

void	ft_draw(t_fractol *img)
{
	float		x;
	float		y;
	t_complex	n;

	x = 0;
	y = 0;
	img->img = mlx_new_image(img->mlx, 800, 800);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (y <= 799)
	{
		while (x <= 799)
		{
			if (ft_iter(&n, (((3 * x) / 800) - 2), ((y / 400) - 1), 500) == 0)
				my_mlx_pixel_put(&(*img), x, y, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractol	img;

	if (ac != 2)
	{
		ft_printf("Fractol: Usage ./fractol Mandelbrot or ./fractol Julia\n");
		return (1);
	}
	if (((ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) != 0) && \
		(ft_strncmp(av[1], "Julia", ft_strlen(av[1])) != 0)))
	{
		ft_printf("Fractol: Usage ./fractol Mandelbrot or ./fractol Julia\n");
		return (1);
	}
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "Fract-ol");
	ft_draw(&img);
	mlx_mouse_hook(img.mlx_win, &ft_mouseevent, &img);
	mlx_key_hook(img.mlx_win, &ft_keyevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
