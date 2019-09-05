/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:06:44 by deladia           #+#    #+#             */
/*   Updated: 2019/09/03 16:06:46 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_fractol(t_fractol *fract)
{
	if (fract->key1 == 'C')
	{
		fract->xmin = -2.5;
		fract->xmax = 1.5;
		fract->ymin = -1.5;
		fract->ymax = 1.5;
	}
	else
	{
		fract->xmin = -2.0;
		fract->xmax = 1.0;
		fract->ymin = -1.0;
		fract->ymax = 1.0;
	}
	set_default(fract);
	return (OK);
}

int		set_default(t_fractol *fract)
{
	fract->repeat = 50;
	fract->x = 750;
	fract->y = 500;
	fract->color = 1;
	fract->flag1 = -1;
	fract->flag2 = -1;
	fract->mouse_jul_y = 250;
	fract->mouse_jul_x = 100;
	return (OK);
}
