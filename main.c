/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 22:11:39 by deladia           #+#    #+#             */
/*   Updated: 2019/09/03 20:33:23 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, SIDE_X + 200, SIDE_Y,
			"fractol");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, SIDE_X, SIDE_Y);
	fract->arr = (int *)mlx_get_data_addr(fract->img_ptr,
			&fract->bit_per_pixel, &fract->size_line, &fract->endian);
	clear_array(fract);
	put_str_on_win(fract);
	create_cl(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
			fract->img_ptr, 200, 0);
	mlx_hook(fract->win_ptr, 2, 0, key_press, fract);
	mlx_hook(fract->win_ptr, 4, 0, mouse_press, fract);
	mlx_hook(fract->win_ptr, 6, 0, mouse_move, fract);
	mlx_hook(fract->win_ptr, 17, 0, close, 0);
	mlx_loop(fract->mlx_ptr);
}

int		read_kernel(t_fractol *fract)
{
	char	*line;
	char	*tmp;
	int		fd;

	if (!(fract->program_source = (char *)ft_memalloc(sizeof(char))))
		return (MEM_NOT_ALLOCATE);
	if ((fd = open("./kernel.cl", O_RDONLY)) < 0)
		return (OPEN_ERROR);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = fract->program_source;
		fract->program_source = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	fract->program_size = ft_strlen(fract->program_source);
	return (OK);
}

int		choose_fractol(char *name, t_fractol *fract)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		fract->key1 = 'A';
	else if (ft_strcmp(name, "Julia") == 0)
		fract->key1 = 'B';
	else if (ft_strcmp(name, "Burning Ship") == 0)
		fract->key1 = 'C';
	else if (ft_strcmp(name, "Mandelbar") == 0)
		fract->key1 = 'D';
	else if (ft_strcmp(name, "Celtic Mandelbar") == 0)
		fract->key1 = 'E';
	else if (ft_strcmp(name, "Perpendicular Mandelbrot") == 0)
		fract->key1 = 'F';
	else
		return (WRONG_NAME);
	return (OK);
}

void	print(void)
{
	ft_putstr("\n\033[031mWrong argument\n\n\033[033mChoose one of:\n"
	"  \033[032m'Mandelbrot'\n  'Julia'\n"
	"  'Burning Ship'\n  'Mandelbar'\n  'Celtic Mandelbar'\n"
"  'Perpendicular Mandelbrot'\n");
}

int		main(int argc, char **argv)
{
	t_fractol		*fract;

	if (argc == 2)
	{
		if (!(fract = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
			return (MEM_NOT_ALLOCATE);
		if (choose_fractol(argv[1], fract) != OK)
		{
			print();
			free(fract);
			return (WRONG_NAME);
		}
		if (!(fract->cl = (t_cl *)ft_memalloc(sizeof(t_cl))))
			return (MEM_NOT_ALLOCATE);
		if (read_kernel(fract) != OK)
			return (READ_ERROR);
		set_fractol(fract);
		control(fract);
	}
	else
		print();
	return (OK);
}
