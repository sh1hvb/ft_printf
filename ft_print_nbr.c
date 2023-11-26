/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:30:13 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/26 17:52:26 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int count_digits(int n) 
{
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n != 0);
    return count;
}

static int handle_negative(int *n, int *j)
{
    if (*n < 0) {
        write(1, "-", 1);
        (*j)++;
        if (*n == -2147483648) {
            write(1, "2147483648", 10);
            return 11;
        }
        *n = -*n;
    }
    return 0;
}

static void print_digit(int n) 
{
    char c = n + '0';
    write(1, &c, 1);
}

int ft_putnbr(int n) 
{
    int j ;

    j = 0;
    if (n == 0) 
    {
        print_digit(0);
        return 1;
    }
    j += count_digits(n);
    if (handle_negative(&n, &j))
        return handle_negative(&n, &j);
    while (n >= 10) {
        print_digit(n % 10);
        n /= 10;
    }
    print_digit(n);
    return j;
}
