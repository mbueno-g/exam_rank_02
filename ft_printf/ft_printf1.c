#include <stdarg.h>
#include <unistd.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	ft_numlen(long long num, int base_len)
{
	int i;
	i = 1;
	while (num >= base_len || num <= -base_len)
	{
		num = num /base_len;
		i++;
	}
	return (i);
}

void	ft_putnum(long long num, char *base, int base_len)
{
	if (num >= base_len)
		ft_putnum(num / base_len, base, base_len);
	write(1, &base[num % base_len], 1);
}

int	ft_printf1(const char *format, ...)
{
	va_list list;
	int i;
	int len;

	int width;
	int precision;
	int point;
	int zeros;
	int spaces;

	char *str;
	int n;

	long num;
	int sign;
	char *base;
	int base_len;

	len = 0;
	width = 0;
	precision = 0;
	point = 0;
	sign = 0;
	zeros = 0;
	spaces = 0;
	va_start(list, format);
	i = -1;
	while(format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0, precision = 0, point = 0, zeros = 0, spaces = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - 48);
				i++;
			}
			if (format[i] == '.')
			{
				i++;
				while (format[i] >= '0' && format[i] <= '9')
				{
					precision = precision * 10 + (format[i] - 48);
					i++;
				}
				point = 1;
			}
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
				n = ft_numlen(num, base_len) + sign;
			}
			if (format[i] == 'x')
			{
				num = va_arg(list, unsigned);
				base = "0123456789abcdef";
				base_len = 16;
				n = ft_numlen(num, base_len);
			}

			if (point && precision > n && format[i] == 's')
				zeros = precision - n + sign;
			else if (point && precision < n && format[i] == 's')
				n = precision;
			else if (point && !precision && (format[i] == 's' || num == 0))
				n = 0;
			spaces = width - n - zeros;
			while(spaces-- > 0)
				len += write(1, ' ', 1);
			if (sign)
				write(1, '-',1);
			while(zeros-- > 0)
				len += write(1, '0', 1);
			if (format[i] == 's')
				write(1, str, n);
			else
				ft_putnum(num, base, base_len);
			len += n;

		}
		else
			len += write(1, &format[i], 1);
	}
	va_end(list);
	return (len);
}
