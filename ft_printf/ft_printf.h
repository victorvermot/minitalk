/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:26:19 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/02 09:17:47 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd, int **count, int **index);
void	ft_putchar_fd(char c, int fd, int **count, int **index);
void	ft_putnbr_fd(int n, int **count, int **index);
void	ft_putnbr_hexa(unsigned int n, int **count, int **index, int maj_min);
int		ft_get_lennbr(int n);
void	ft_putnbr_p(unsigned long int n, int **count, int **index);
void	ft_putnbr_fd_unsigned(unsigned int n, int **count, int **index);

#endif