/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:03 by corellan          #+#    #+#             */
/*   Updated: 2023/01/16 15:24:52 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
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
	int		mouse_flag;
}			t_fractol;

typedef struct s_complex
{
	float	x;
	float	y;
	float	x_z;
	float	y_z;
	float	x_c;
	float	y_c;	
}			t_complex;

int		fcolor(unsigned char t, unsigned char r, unsigned char g, \
	unsigned char b);
void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color);
int		destroy(t_fractol *img);
int		ft_mousedownevent(int button, int x, int y, t_fractol *img);
int		ft_iter(t_complex *n, float limit, int iter);
void	ft_julia_move(t_fractol *img, int xm, int ym);

#endif
