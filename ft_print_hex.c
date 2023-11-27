/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:10:03 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/27 16:40:54 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 

static int lenn(unsigned long nb)
{
    int i = 0;

    while (nb != 0)
    {
        nb = nb / 16;
        i++;
    }
    return i;
}

static int insert(unsigned long nb, char *nbr, char *base)
{
    int n;
    int i = 0;

    while (nb > 0)
    {
        n = nb % 16; 
        nb = nb / 16;
        nbr[i] = base[n];
        i++;
    }
    nbr[i]='\0';
    return i;
}


int ft_print_hex(unsigned long n)
{
    int indexing;
    char *base;
    int res = 0;  
    int len;
    char *nbr;

    base = ft_strdup("0123456789abcdef");
    if (base == NULL)
        return (0);  
    if (n == 0)
        res += write(1, "0", 1);
    len = lenn(n);
    nbr = malloc(len + 1);  
    if (nbr == NULL)
    {   
        free(base);
        return (0);  
    }
    indexing = insert(n, nbr, base);
    while (indexing--)
        res += write(1, &nbr[indexing], 1);
    free(nbr);
    free(base);
    return res;
}