/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:56:06 by deladia           #+#    #+#             */
/*   Updated: 2019/09/01 21:56:08 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_fractol *fract)
{
	fract->arr = clear_array(fract);
	if (fract->flag1 == 1)
	{
		fract->x -= fract->mouse_x - x;
		fract->y -= fract->mouse_y - y;
		fract->mouse_x = x;
		fract->mouse_y = y;
	}
	if (fract->flag2 == 1)
	{
		fract->mouse_jul_x -= fract->mouse_x - x;
		fract->mouse_jul_y -= fract->mouse_y - y;
		fract->mouse_x = x;
		fract->mouse_y = y;
	}
	set_arg(fract, fract->cl);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
			fract->img_ptr, 200, 0);
	return (OK);
}

int		mouse_press_1(int button, int x, int y, t_fractol *fract)
{
	if (button == 1)
	{
		fract->flag1 *= -1;
		fract->mouse_x = x;
		fract->mouse_y = y;
	}
	if (button == 2)
	{
		fract->flag2 *= -1;
		fract->mouse_x = x;
		fract->mouse_y = y;
	}
	set_arg(fract, fract->cl);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
							fract->img_ptr, 200, 0);
	return (OK);
}

int		mouse_press_0(int button, int x, int y, t_fractol *fract)
{
	double		xmin;
	double		xmax;
	double		ymax;
	double		ymin;

	xmin = fract->xmin;
	xmax = fract->xmax;
	ymin = fract->ymin;
	ymax = fract->ymax;
	if (button == 5)
	{
		fract->xmin = xmin - xmin * (xmax - xmin) / SIDE_X * 100;
		fract->ymin = ymin - ymin * (ymax - ymin) / SIDE_Y * 100;
		fract->xmax = xmax - xmax * (xmax - xmin) / SIDE_X * 100;
		fract->ymax = ymax - ymax * (ymax - ymin) / SIDE_Y * 100;
		fract->x += (double)(750.0 - x) / 4;
		fract->y += (double)(500.0 - y) / 4;
	}
	return (OK);
}

int		mouse_press(int button, int x, int y, t_fractol *fract)
{
	double		xmin;
	double		xmax;
	double		ymax;
	double		ymin;

	fract->arr = clear_array(fract);
	xmin = fract->xmin;
	xmax = fract->xmax;
	ymin = fract->ymin;
	ymax = fract->ymax;
	if (button == 4 && fract->xmin > -3.0)
	{
		fract->xmin = xmin + xmin * (xmax - xmin) / SIDE_X * 200;
		fract->ymin = ymin + ymin * (ymax - ymin) / SIDE_Y * 200;
		fract->xmax = xmax + xmax * (xmax - xmin) / SIDE_X * 200;
		fract->ymax = ymax + ymax * (ymax - ymin) / SIDE_Y * 200;
		fract->x -= (double)(750.0 - x) / 4;
		fract->y -= (double)(500.0 - y) / 4;
	}
	mouse_press_0(button, x, y, fract);
	mouse_press_1(button, x, y, fract);
	return (OK);
}
