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
stactic void clear(void *p)
{
    char *a = (char *)p;
    while(*a)
        free(a++);
    free(a);
}
static int len(int nb)
{
    int i;

    i = 0;
    while(nb != 0)
    {
        nb = nb /10;
        i++;
    }
    return (i)
}
static int insert(unsigned long nb , char *nbr , int base)
{
    int n ;
    int i ;

    i = 0;
    n = 0;
    while(nb > 0)
    {
        n = nb % 16;
        nb = nb / 16;
        nbr[i] =  base[n];
        i++; 
    }
    return (i);
}



int ft_print_hex(unsigned long n)
{
  int indexing;
  char *base;
  int res;
  int len;
  char *nbr;


    base = ft_strdup("012345678abcdef\0");
    if(n == 0)
        res += write(1,"0",1);
    len = len(n);
    nbr =(char *)malloc(len);
    indexing = insert(n,nbr,base);
    while(indexing)
    {
        res+=write(1,&nbr[i],1);
    }
    clear(nbr);
    return (res);
}