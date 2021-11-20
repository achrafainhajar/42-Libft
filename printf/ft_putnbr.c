/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:34:08 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/20 04:40:29 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long n, int i, int *l,char *str)
{
	long	nb;

	nb = (long) n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-',l);
	}
	if (nb < i)
	{
		ft_putchar(str[nb],l);
	}
	else
	{
		ft_putnbr((nb / i), i, l,str);
		ft_putnbr((nb % i), i, l,str);
	}
}
