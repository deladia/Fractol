/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:57:30 by deladia           #+#    #+#             */
/*   Updated: 2019/09/01 21:57:32 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# include "mlx.h"
# include <OpenCL/opencl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# define SIDE_Y 1000
# define SIDE_X 1500
# define READ_ERROR 23
# define OPEN_ERROR 24
# define MEM_NOT_ALLOCATE 1
# define WRONG_NAME 25
# define OK	0

typedef struct			s_cl
{
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_context			context;
	cl_uint				ret_num_devices;
	cl_command_queue	cmd_queue;
	cl_program			program;
	cl_kernel			kernel;
	size_t				global_work_size[1];
	cl_device_id		device_id;
	cl_mem				memobjs;
}						t_cl;

typedef struct			s_fractol
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					color;
	int					*arr;
	double				x;
	double				y;
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	char				key1;
	int					bit_per_pixel;
	int					size_line;
	int					endian;
	char				*program_source;
	int					repeat;
	size_t				program_size;
	t_cl				*cl;
	int					flag1;
	int					flag2;
	int					mouse_x;
	int					mouse_y;
	int					mouse_jul_x;
	int					mouse_jul_y;
}						t_fractol;

int						create_cl(t_fractol *fract);
int						set_arg(t_fractol *fract, t_cl *cl);
void					func_error(int err);
void					fractol_free(t_fractol **fract);
int						*clear_array(t_fractol *fract);
int						mouse_press(int button, int x, int y, t_fractol *fract);
int						mouse_move(int x, int y, t_fractol *fract);
int						set_default(t_fractol *fract);
int						set_fractol(t_fractol *fract);
int						put_str_on_win(t_fractol *fract);
int						key_press(int keycode, t_fractol *fract);

#endif
