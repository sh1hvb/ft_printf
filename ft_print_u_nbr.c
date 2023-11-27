/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:24:13 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/27 12:40:28 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putnbr_unsigned(unsigned int n) 
{
    char c;
    int count = 0;  
    unsigned int temp = n;
    unsigned int divisor = 1;

    
    while (temp / 10 > 0) {
        divisor *= 10;
        temp /= 10;
    }

   
    while (divisor > 0) {
        c = n / divisor + '0';
        write(1, &c, 1);
        n %= divisor;
        divisor /= 10;
        count++;  
    }

    return count;
}
