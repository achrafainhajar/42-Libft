/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:58:27 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/20 05:08:14 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int ft_printf(const char *str, ...)
{
    int i;
    int l;
    l = 0;
    va_list arg;
    va_start(arg, str);
    char c;
    i = 0;
    void *test;
    while (str[i] != '%' && str[i])
        ft_putchar(str[i++],&l);
    if (str[i++] == '%')
    {
        if (str[i] == 'c')
            ft_putchar(va_arg(arg,int),&l);
        else if (str[i] == 's')
        {
            test = va_arg(arg,char *);
            if (test == NULL)
                ft_putstr("(null)",&l);
            else
                ft_putstr(test,&l);
        }
        else if (str[i] == 'd' || str[i] == 'i')
            ft_putnbr(va_arg(arg,int),10, &l,"0123456789");
        else if (str[i] == 'u')
            ft_putnbr((unsigned int)va_arg(arg,unsigned int),10,&l, "0123456789");
        else if(str[i] == 'p')
        {
            ft_putstr("0x",&l);
            ft_putnbr((long)va_arg(arg, long), 16, &l, "0123456789abcdef");
        }
        else if (str[i] == 'x')
            ft_putnbr((long)va_arg(arg, unsigned int), 16, &l, "0123456789abcdef");
        else if (str[i] == 'X')
            ft_putnbr((long)va_arg(arg, long), 16, &l, "0123456789ABCDEF");
        else if (str[i] == '%')
            ft_putchar('%',&l);
        else
        {
            ft_putstr((char *)(i + str),&l);
            return (l);
        }
    }
    ft_putstr((char *)(i + str),&l);
    return (l);
}
int main()
{  
    char s[]="test";
    int *i;
    *i= 16;
    ft_printf("%s",s);
    //printf("%s",s);
}