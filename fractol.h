/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:03 by corellan          #+#    #+#             */
/*   Updated: 2023/01/15 23:07:19 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include "libft/libft.h"

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
}			t_fractol;

typedef struct s_complex
{
	float	x;
	float	y;
	float	x_c;
	float	y_c;
	float	x_i;
	float	y_i;	
}			t_complex;

int		fcolor(unsigned char t, unsigned char r, unsigned char g, \
	unsigned char b);
void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color);
int		destroy(t_fractol *img);
int		ft_mouseevent(int button, int x, int y, t_fractol *img);
int		ft_keyevent(int keycode);
void	ft_redraw(t_fractol *img, int color);
int		ft_iter_mandelbrot(t_complex *n, float x_init, float y_init, int iter);
int		ft_iter_julia(t_complex *n, float x_c, float y_c, int iter);

#endif
