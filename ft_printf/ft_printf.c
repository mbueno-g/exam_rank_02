#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

int len;

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnum(long long num, char *base, int base_len)
{
	if (num >= base_len)
		ft_putnum(num / base_len, base, base_len);
	len += write(1, &base[num % base_len], 1);
}

/*int	ft_numlen(long long num, int base_len)
{
	int i;
	i = 1;
	while (num >= base_len || num <= -base_len)
	{
		num = num /base_len;
		i++;
	}
	return (i);
}*/

int	ft_printf(const char *format, ...)
{
	va_list list;
	int i;
	//int len;

	char *str;
	int n;

	long num;
	int sign;
	char minus;
	char *base;
	int base_len;

	str = NULL;
	n = 0;
	num = 0;
	//len = 0;
	sign = 0;
	minus = '-';
	base = NULL;
	base_len = 0;
	va_start(list, format);
	i = -1;
	while(format[++i])
	{
		if (format[i] == '%')
		{
			sign = 0;
			i++;
			if (format[i] == 's')
			{
				str = va_arg(list, char *);
				if(!str)
					str = "(null)";
				n = ft_strlen(str);
			}
			if (format[i] == 'd')
			{
				num = va_arg(list, int);
				base = "0123456789";
				base_len = 10;
				if (num < 0)
				{
					num = -num;
					sign = 1;
				}
				//n = ft_numlen(num, base_len) + sign;
			}
			if (format[i] == 'x')
			{
				num = va_arg(list, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
				//n = ft_numlen(num, base_len);
			}
			if (sign)
				len += write(1,&minus,1);
			if (format[i] == 's')
				write(1, str, n);
			else
				ft_putnum(num, base, base_len);
			//len += n;
		}
		else
			len += write(1, &format[i], 1);
	}
	va_end(list);
	return (len);
}
