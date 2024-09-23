/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:46:18 by corellan          #+#    #+#             */
/*   Updated: 2023/01/24 18:18:11 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_check_flags(t_fractol *img, char **av)
{
	if (img->flag == 0)
		mandelbrot_i(&(*img), &ft_iter);
	else if (img->flag == 1)
	{
		img->signal = 0;
		julia_i(&(*img), av, &ft_iter);
	}
	else if (img->flag == 2)
		mandelbrot_i(&(*img), &ft_iter_mult);
	else
	{
		img->signal = 0;
		julia_i(&(*img), av, &ft_iter_mult);
	}
}

static int	ft_printerror(void)
{
	ft_printf("Fractol: input error\n");
	ft_printf("Usage:\n");
	ft_printf("./fractol [fractals]\n\n");
	ft_printf(" Example:\n ./fractol mandelbrot\n\n");
	ft_printf("[Fractals] available:\n");
	ft_printf("-> mandelbrot\n-> julia\n-> multibrot\n-> filled_julia\n\n");
	ft_printf("In the case of julia and filled_julia, you must declare ");
	ft_printf("initial coordinates. For example:\n");
	ft_printf(" ./fractol julia -0.8 0.1\n\n");
	ft_printf("The julia set can be iterated between -2 and 2. ");
	ft_printf("Also, the filled_julia set can be ");
	ft_printf("iterated between -1.4 and 1.4.\n\n");
	return (1);
}

static int	ft_checker_julias(t_fractol *img, char **av)
{
	if ((ft_strncmp(av[1], "mandelbrot", 12) == 0) || \
		(ft_strncmp(av[1], "multibrot", 11) == 0))
		return (0);
	if (ft_argument_checker(av[2]) < ft_strlen(av[2]))
		return (-1);
	if (ft_argument_checker(av[3]) < ft_strlen(av[3]))
		return (-1);
	img->i_x = ft_atof(av[2]);
	img->i_y = ft_atof(av[3]);
	if ((ft_strncmp(av[1], "julia", 6) == 0) && ((img->i_x > 2 || \
		img->i_x < -2) || (img->i_y > 2 || img->i_y < -2)))
		return (-1);
	if ((ft_strncmp(av[1], "filled_julia", 14) == 0) && ((img->i_x > 1.4 || \
		img->i_x < -1.4) || (img->i_y > 1.4 || img->i_y < -1.4)))
		return (-1);
	return (0);
}

static int	ft_checker(t_fractol *img, int ac, char **av)
{
	if (ac == 1)
		return (ft_printerror());
	if ((ft_strncmp(av[1], "julia", 6) == 0 && (ac != 4)) || \
		(ft_strncmp(av[1], "mandelbrot", 12) == 0 && (ac != 2)))
		return (ft_printerror());
	if ((ft_strncmp(av[1], "filled_julia", 14) == 0 && (ac != 4)) || \
		(ft_strncmp(av[1], "multibrot", 11) == 0 && (ac != 2)))
		return (ft_printerror());
	if (((ft_strncmp(av[1], "mandelbrot", 12)) != 0) && \
		(ft_strncmp(av[1], "julia", 6) != 0) && \
		((ft_strncmp(av[1], "filled_julia", 14) != 0)) && \
		(ft_strncmp(av[1], "multibrot", 11) != 0))
		return (ft_printerror());
	if (ft_checker_julias(&(*img), av) == -1)
		return (ft_printerror());
	if ((ft_strncmp(av[1], "mandelbrot", 12) == 0))
		img->flag = 0;
	else if ((ft_strncmp(av[1], "julia", 6) == 0))
		img->flag = 1;
	else if ((ft_strncmp(av[1], "multibrot", 11) == 0))
		img->flag = 2;
	else
		img->flag = 3;
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	img;

	img.signal_key = 0;
	if (ft_checker(&img, ac, av) == 1)
		return (1);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 600, "Fract-ol");
	ft_color1(&img);
	ft_check_flags(&img, av);
	if (img.signal_key == 0)
		ft_float(&img);
	mlx_hook(img.mlx_win, 4, 0, &ft_mousedownevent, &img);
	mlx_key_hook(img.mlx_win, &ft_keydownevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
