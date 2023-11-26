/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:10:03 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/25 17:47:54 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_print_hex(long n,int base)
{
    int count;
    char *sym;

    sym = "0123456789abcdef";
    if(n < 0)
    {
        write(1,"-",1);
        return ft_print_hex(-n,base) + 1;
    }
    else if(n < base)
        return ft_print_chr(sym[n]);
    else
    {
        count += ft_print_hex( n / base, base);
    }
    return count += ft_print_hex(n % base,base);
}