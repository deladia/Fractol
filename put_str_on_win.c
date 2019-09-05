/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_on_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:12:11 by deladia           #+#    #+#             */
/*   Updated: 2019/09/03 17:12:13 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		print_fractol_name(t_fractol *f)
{
	if (f->key1 == 'A')
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF, "Mandelbrot");
	else if (f->key1 == 'B')
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF, "Julia");
	else if (f->key1 == 'C')
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF,
				"Burning Ship");
	else if (f->key1 == 'D')
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF, "Mandelbar");
	else if (f->key1 == 'E')
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF,
				"Celtic Mandelbar");
	else if (f->key1 == 'F')
	{
		mlx_string_put(f->mlx_ptr, f->win_ptr, 20, 120, 0x0000FF,
				"Perpendicular");
		mlx_string_put(f->mlx_ptr, f->win_ptr, 40, 150, 0x0000FF, "Mandelbrot");
	}
	return (OK);
}

int		print_key_control(t_fractol *f)
{
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 180, 0xFF0000,
			"Color = [1 .. 9]");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 200, 0xFF0000,
			"Zoom = Mouse wheel");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 220, 0xFF0000, "Move = W A S D");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 50, 240, 0xFF0000, "or = LBM");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 260, 0xFF0000, "Julia = RBM");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 280, 0xFF0000, "Default = K");
	mlx_string_put(f->mlx_ptr, f->win_ptr, 10, 300, 0xFF0000,
			"Next fract = TAB");
	return (OK);
}

int		put_str_on_win(t_fractol *fract)
{
	char	*str;

	mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
	str = ft_itoa(fract->repeat);
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 20, 20, 0x00FF00,
			"Repeats(-/+)=");
	mlx_string_put(fract->mlx_ptr, fract->win_ptr, 150, 20, 0x00FF00, str);
	print_key_control(fract);
	print_fractol_name(fract);
	free(str);
	return (OK);
}
