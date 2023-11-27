

#include "ft_printf.h"
#include <limits.h>
int main()
{
  char a[] ="habibi";

printf("%d", ft_printf("\n%X\n%x\n%d\n%s\n%p\n",NULL));
    printf("\n");
    system("leaks a.out");
    printf("%d", ft_printf("\n%X\n%x\n%d\n%s\n%p\n",NULL));
    
}
