/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:52:42 by deladia           #+#    #+#             */
/*   Updated: 2019/09/01 21:52:44 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	func_error_1(int err)
{
	if (err == -7)
		ft_putstr("Building program error");
	else if (err == -8)
		ft_putstr("Creation kernel error");
	else if (err == -9)
		ft_putstr("Set arguments kernel error");
	else if (err == -10)
		ft_putstr("Write buffer error");
	else if (err == -11)
		ft_putstr("EnqueueNDRangeKernel error");
	else if (err == -12)
		ft_putstr("Read buffer error");
}

void	func_error(int err)
{
	if (err == -1)
		ft_putstr("Platform ID error");
	else if (err == -2)
		ft_putstr("Devise ID error");
	else if (err == -3)
		ft_putstr("Creation context error");
	else if (err == -4)
		ft_putstr("Creation command queue error");
	else if (err == -5)
		ft_putstr("Creation buffer error");
	else if (err == -6)
		ft_putstr("Creation program error");
	func_error_1(err);
	exit(1);
}
