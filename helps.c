/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:54:37 by deladia           #+#    #+#             */
/*   Updated: 2019/09/01 21:54:50 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*clear_array(t_fractol *fract)
{
	int		i;

	i = 0;
	while (i <= (SIDE_X * SIDE_Y))
	{
		fract->arr[i] = 0xFFFFFF;
		i++;
	}
	return (fract->arr);
}

void	fractol_free(t_fractol **fract)
{
	free((*fract)->cl);
	free((*fract)->program_source);
	free(*fract);
}
