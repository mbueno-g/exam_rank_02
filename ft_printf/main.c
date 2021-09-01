#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("len a %d\n", printf("a%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("len b %d\n", ft_printf("b%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}
