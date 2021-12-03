/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:00:08 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/03 17:09:23 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	send_bits(int pid, char *msg)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(msg);
	while (i <= len)
	{
		j = 0;
		while (j < 7)
		{
			if ((msg[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			pid;

	if (argc != 3)
	{
		ft_printf("Please enter 2 valid arguments");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	send_bits(pid, argv[2]);
	return (0);
}
