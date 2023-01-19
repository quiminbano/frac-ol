/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:50 by corellan          #+#    #+#             */
/*   Updated: 2023/01/18 20:49:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fcolor(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	int	tr;
	int	re;
	int	gr;
	int	bl;

	tr = ((255 * t) / 100);
	tr = (unsigned char)tr;
	re = (int)r;
	gr = (int)g;
	bl = (int)b;
	return (tr << 24 | re << 16 | gr << 8 | bl);
}
