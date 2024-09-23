/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:03 by corellan          #+#    #+#             */
/*   Updated: 2023/01/25 16:34:09 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
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
	int		signal;
	int		signal_key;
	int		signal_zoom;
	float	xm;
	float	ym;
	int		m_x;
	int		m_y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	i_x;
	float	i_y;
	float	*zoom;
	float	zoom_old;
	float	*ud;
	float	*lr;
	int		color1;
	int		color2;
	int		color3;
	int		color4;
	int		color5;
	int		color6;
	int		color7;
	int		color8;
	int		color9;
	int		color10;
	int		color11;
	int		background;
}			t_fractol;

typedef struct s_complex
{
	float	x;
	float	y;
	float	xz;
	float	yz;
	float	xc;
	float	yc;
	float	r;
	float	im;
	int		i;	
}			t_complex;

int		fcolor(unsigned char t, unsigned char r, unsigned char g, \
	unsigned char b);
void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color);
void	ft_float(t_fractol *img);
int		destroy(t_fractol *img);
int		ft_mousedownevent(int button, int x, int y, t_fractol *img);
void	ft_mouse_aux(t_fractol *img, int button, float *zoom);
int		ft_keydownevent(int keycode, t_fractol *img);
void	ft_iter(t_fractol *img, t_complex *n);
void	ft_iter_mult(t_fractol *img, t_complex *n);
void	julia_i(t_fractol *img, char **av, void (*f)(t_fractol *, \
	t_complex *));
void	mandelbrot_i(t_fractol *img, void (*f)(t_fractol *, t_complex *));
void	jul_z(t_fractol *img, float zoom, void (*f)(t_fractol *, t_complex *));
void	man_z(t_fractol *img, float zoom, void (*f)(t_fractol *, t_complex *));
void	ft_check_flags_event(t_fractol *img, float zoom);
void	ft_put_black(t_fractol *img);
void	ft_put_color(t_fractol *img, t_complex *n);
void	ft_color_changer(int keycode, t_fractol *img);
void	ft_color1(t_fractol *img);
void	ft_color5(t_fractol *img);
size_t	ft_argument_checker(char *str);
double	ft_atof(char *str);

#endif
