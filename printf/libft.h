/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:40:08 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/20 04:37:21 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
#include<stdarg.h>


void	ft_putchar(char c,int *l);
void	ft_putstr(char *s , int *l);
void	ft_putendl(char *s);
void	ft_putnbr(long n, int i,int *l,char *str);
int ft_printf(const char *str, ...);

#endif