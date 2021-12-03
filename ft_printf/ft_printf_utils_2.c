/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:27:10 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/02 09:21:43 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// Conversion from base 10 to base 16
static int	ft_base_conversion(unsigned long int n, int *count, int maj_min)
{
	char	temp;

	if (n)
	{
		ft_base_conversion(n / 16, count, maj_min);
		temp = (n % 16);
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + maj_min;
		*count = *count + 1;
		write(1, &temp, sizeof(temp));
	}
	return (0);
}

// Receive a number and send it to be converted to hexa
void	ft_putnbr_hexa(unsigned int n, int **count, int **index, int maj_min)
{
	char	temp;

	temp = '0';
	if (n == 0)
	{
		write(1, &temp, sizeof(temp));
		**count += 1;
	}
	else
		ft_base_conversion(n, *count, maj_min);
	**index = **index + 1;
}

// Receive a pointer and returns the adress in hexa
void	ft_putnbr_p(unsigned long int n, int **count, int **index)
{
	char	temp;

	temp = '0';
	ft_putstr_fd("0x", 1, count, index);
	if (n == 0)
	{
		write(1, &temp, sizeof(temp));
		**count += 1;
	}
	else
		ft_base_conversion(n, *count, 87);
}

// Writes an unsigned int in base 10
static int	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	temp;

	if (n > 0)
	{
		ft_putnbr_unsigned(n / 10, count);
		temp = (n % 10) + 48;
		*count += 1;
		write(1, &temp, sizeof(temp));
	}
	return (0);
}

// Receive an unsigned int in base 10
void	ft_putnbr_fd_unsigned(unsigned int n, int **count, int **index)
{
	char	temp;

	temp = '0';
	if (n == 0)
	{
		write(1, &temp, sizeof(temp));
		**count += 1;
	}
	else
		ft_putnbr_unsigned(n,*count);
	**index = **index + 1;
}
