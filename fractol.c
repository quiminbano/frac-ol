/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:18 by corellan          #+#    #+#             */
/*   Updated: 2023/01/19 23:23:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia_init(t_fractol *img, char **av)
{
	t_complex	n;

	n.r = 0;
	n.im = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (n.im <= 599)
	{
		while (n.r <= 799)
		{
			n.x_z = ((n.r / 200) - 2);
			n.y_z = ((n.im / 200) - 1.5);
			n.x_c = atof(av[2]);
			n.y_c = atof(av[3]);
			img->i_x = n.x_c;
			img->i_y = n.y_c;
			ft_iter(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

static void	ft_mandelbrot_init(t_fractol *img)
{
	t_complex	n;

	n.r = 0;
	n.im = 0;
	img->img = mlx_new_image(img->mlx, 800, 600);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	while (n.im <= 599)
	{
		while (n.r <= 799)
		{
			n.x_c = ((n.r / 200) - 2);
			n.y_c = ((n.im / 200) - 1.5);
			n.x_z = 0;
			n.y_z = 0;
			ft_iter(&(*img), &n);
			(n.r)++;
		}
		(n.im)++;
		n.r = 0;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

static void	ft_printerror(void)
{
	ft_printf("Fractol: input error\n");
	ft_printf("Usage:\n");
	ft_printf("./fractol mandelbrot ");
	ft_printf("or ");
	ft_printf("./fractol julia coordinate_real coordinate_imaginary\n");
}

static int	ft_checker(t_fractol *img, int ac, char **av)
{
	if (ac == 1)
	{
		ft_printerror();
		return (1);
	}
	if ((ft_strncmp(av[1], "julia", 6) == 0 && (ac != 4)) || \
		(ft_strncmp(av[1], "mandelbrot", 12) == 0 && (ac != 2)))
	{
		ft_printerror();
		return (1);
	}
	if (((ft_strncmp(av[1], "mandelbrot", 12)) != 0) && \
		(ft_strncmp(av[1], "julia", 6) != 0))
	{
		ft_printerror();
		return (1);
	}
	if ((ft_strncmp(av[1], "mandelbrot", 12) == 0))
		img->flag = 0;
	else
		img->flag = 1;
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	img;

	if (ft_checker(&img, ac, av) == 1)
		return (1);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 600, "Fract-ol");
	if (img.flag == 0)
		ft_mandelbrot_init(&img);
	else
	{
		img.signal = 0;
		ft_julia_init(&img, av);
	}
	mlx_hook(img.mlx_win, 4, 0, &ft_mousedownevent, &img);
	mlx_key_hook(img.mlx_win, &ft_keydownevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
