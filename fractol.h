/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:03 by corellan          #+#    #+#             */
/*   Updated: 2024/09/23 11:15:37 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
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
	float	xm;
	float	ym;
	float	i_x;
	float	i_y;

}			t_fractol;

typedef struct s_complex
{
	float	x;
	float	y;
	float	x_z;
	float	y_z;
	float	x_c;
	float	y_c;
	float	r;
	float	im;
	int		i;	
}			t_complex;

int		fcolor(unsigned char t, unsigned char r, unsigned char g, \
	unsigned char b);
void	my_mlx_pixel_put(t_fractol *img, int x, int y, int color);
int		destroy(t_fractol *img);
int		ft_mousedownevent(int button, int x, int y, t_fractol *img);
int		ft_keydownevent(int keycode, t_fractol *img);
void	ft_mouse_aux(t_fractol *img, int button, float *zoom);
void	ft_iter(t_fractol *img, t_complex *n);
void	ft_julia_move_zoom(t_fractol *img, int xm, int ym, float zoom);
void	ft_checker_coord(t_fractol *img, t_complex *n, float xm, float ym);
void	ft_mandelbrot_zoom(t_fractol *img, float zoom);
void	ft_put_black(t_fractol *img);
double	ft_atof(char *str);
int		ft_checker_julia(t_fractol *img, char **av);

#endif
