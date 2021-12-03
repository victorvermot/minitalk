/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:29:28 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/02 10:51:37 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = -1;
	while (s1[++i])
		;
	ret = (char *)malloc(i * sizeof(const char) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}

// Writes a string and "(null)"" in case it's empty
void	ft_putstr_fd(char *s, int fd, int **count, int **index)
{
	int		i;
	char	*null;

	null = ft_strdup("(null)");
	i = -1;
	if (s)
	{
		while (s[++i])
		{
			write(fd, &s[i], sizeof(s[i]));
			**count += 1;
		}
	}
	else
	{
		while (null[++i])
		{
			write(fd, &null[i], sizeof(null[i]));
			**count += 1;
		}
	}
	free(null);
	**index = **index + 1;
}

int	ft_get_lennbr(int n)
{
	int	len;

	if (n < 0 || n == 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// Writes a simple integer in base 10
static int	ft_putnbr_recu(int n)
{
	int		i;
	char	temp;

	i = -1;
	if (n == -2147483648)
	{
		n *= -1;
		ft_putnbr_recu(n / 10);
		temp = '8';
		write(1, &temp, sizeof(temp));
	}
	else if (n < 0)
	{
		n *= -1;
		temp = '-';
		write(1, &temp, sizeof(temp));
	}
	if (n > 0)
	{
		ft_putnbr_recu(n / 10);
		temp = (n % 10) + 48;
		write(1, &temp, sizeof(temp));
	}
	return (0);
}

// Receive a number and sends it to be written
void	ft_putnbr_fd(int n, int **count, int **index)
{
	char	temp;

	temp = '0';
	if (n == 0)
		write(1, &temp, sizeof(temp));
	else
		ft_putnbr_recu(n);
	**index = **index + 1;
	**count += ft_get_lennbr(n);
}
