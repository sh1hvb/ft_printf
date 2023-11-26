/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:15:16 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/25 20:01:21 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_print_string(char *str)
{
    int count;
    int i;

    i = 0; 
    count = 0;
    while (str[i])
    {
        ft_print_chr(str[i]);
        i++;
        count++;
    }
    return (count);  
}