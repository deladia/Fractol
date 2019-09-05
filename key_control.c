/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:33:01 by deladia           #+#    #+#             */
/*   Updated: 2019/09/03 20:33:03 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		next_fractol(t_fractol *fract)
{
	if (fract->key1 != 'F')
		fract->key1++;
	else
		fract->key1 = 'A';
	return (OK);
}

int		key_press_1(int keycode, t_fractol *fract)
{
	if (keycode == 18)
		fract->color = 1;
	if (keycode == 19)
		fract->color = 0xFFFFFF;
	if (keycode == 20)
		fract->color = 0x00FFFF;
	if (keycode == 21)
		fract->color = 0x0000CD;
	if (keycode == 23)
		fract->color = 40;
	if (keycode == 22)
		fract->color = 45;
	if (keycode == 26)
		fract->color = 65;
	if (keycode == 28)
		fract->color = 10;
	if (keycode == 25)
		fract->color = 5;
	if (keycode == 48)
		next_fractol(fract);
	if (keycode == 40)
		set_fractol(fract);
	return (OK);
}

int		key_press(int keycode, t_fractol *fract)
{
	fract->arr = clear_array(fract);
	if (keycode == 53)
	{
		fractol_free(&fract);
		exit(OK);
	}
	if (keycode == 0)
		fract->x -= 15;
	if (keycode == 1)
		fract->y += 15;
	if (keycode == 2)
		fract->x += 15;
	if (keycode == 13)
		fract->y -= 15;
	if (keycode == 69)
		fract->repeat += 1;
	if (keycode == 78 && fract->repeat > 1)
		fract->repeat -= 1;
	key_press_1(keycode, fract);
	put_str_on_win(fract);
	set_arg(fract, fract->cl);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
							fract->img_ptr, 200, 0);
	return (OK);
}

int		close(int param)
{
	(void)param;
	exit(OK);
}
