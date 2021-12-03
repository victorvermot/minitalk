/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:59:56 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/03 17:29:31 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_binaire	g_binaire;

void	get_binary_number(int signum)
{
	g_binaire.c += ((signum & 1) << g_binaire.size);
	ft_printf("%d\n", g_binaire.c);
	g_binaire.size++;
	if (g_binaire.size == 7)
	{
		ft_printf("%c", g_binaire.c);
		if (!g_binaire.c)
			ft_printf("\n");
		g_binaire.c = 0;
		g_binaire.size = 0;
	}
}

int	main(void)
{
	g_binaire.size = 0;
	g_binaire.c = 0;
	ft_printf("PID du serveur : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, get_binary_number);
		signal(SIGUSR1, get_binary_number);
		pause();
	}
	return (0);
}
