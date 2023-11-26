/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:01:37 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/25 20:02:41 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_printf_format(char spex, va_list ap)
{
    int count;

    count = 0;
    if(spex == 'c')
       count += ft_print_chr(va_arg(ap, int));
    else if(spex == 's')
       count +=  ft_print_string(va_arg(ap, char *));
    else if(spex == 'p')
        count += ft_print_hex((unsigned long)va_arg(ap, char *),16);
    else if(spex == 'd' || spex == 'i')
        count += ft_print_hex((unsigned long)va_arg(ap, int), 10);
    else if(spex == 'u')
        count += ft_print_hex((unsigned long)va_arg(ap, unsigned int),10);
    else if(spex == 'x')
        count += ft_print_hex((unsigned long)va_arg(ap, unsigned int),16);
    else if( spex == 'X')
        count +=  ft_print_upper_hex((unsigned long)va_arg(ap, unsigned int),16);
    else if( spex == '%')
        count +=  write(1, &spex , 1);
    else 
        count += write(1, &spex , 1);
    return (count);
    
}
int ft_printf(const char *f, ...)
{
    va_list ap;
    int count ;
    va_start(ap,f);
    count = 0;
    while ((*f))
    {
        if(*f =='%')
            count += ft_printf_format(*(++f),ap);
        else
            count += write(1,f,1);
        ++f;
    }
    va_end(ap);
    return count; 
}
int main()
{
  ft_printf("%X", 123);
}
