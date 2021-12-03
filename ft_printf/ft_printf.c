/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:23:01 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/02 11:02:50 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int **count, int **index)
{
	write(fd, &c, sizeof(c));
	**count = **count + 1;
	**index = **index + 1;
}

void	ft_is_formated(const char *str, va_list args, int *i, int *count)
{
	if (str[*i] == '%' && str[*i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, &count, &i);
	else if (str[*i] == '%' && str[*i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, &count, &i);
	else if (str[*i] == '%' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
		ft_putnbr_fd(va_arg(args, int), &count, &i);
	else if (str[*i] == '%' && str[*i + 1] == 'u')
		ft_putnbr_fd_unsigned(va_arg(args, unsigned int), &count, &i);
	else if (str[*i] == '%' && str[*i + 1] == '%')
		ft_putchar_fd('%', 1, &count, &i);
	else if (str[*i] == '%' && str[*i + 1] == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), &count, &i, 55);
	else if (str[*i] == '%' && str[*i + 1] == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), &count, &i, 87);
	else if (str[*i] == '%' && str[*i + 1] == 'p')
		ft_putnbr_p(va_arg(args, unsigned long int), &count, &i);
	else
	{
		ft_putchar_fd(str[*i], 1, &count, &i);
		*i -= 1;
	}
	*i += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
		ft_is_formated(str, args, &i, &count);
	va_end(args);
	return (count);
}
