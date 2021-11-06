#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	ft_putstr_fd(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10);
		ft_putchar_fd(n % 10 + '0');
	}
	else
		ft_putchar_fd(n + '0');
}

int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	const char *p;

	va_start(ap, str);
	p = str;
	while (*p)
	{
		if (*p == 'c')
		{
			char cval;
			cval = va_arg(ap, int);
			ft_putchar_fd(cval);
		}
		else if (*p == 's')
		{
			//for(char *sval = va_arg(ap, char *); *sval; sval++)
			//	putchar(*sval);
			char *sval;
			sval = va_arg(ap, char *);
			ft_putstr_fd(sval);
		}
		else if (*p == 'd')
		{
			int ival;
			ival = va_arg(ap, int);
			ft_putnbr_fd(ival);
		}
		else if (*p == 'f')
		{
			double  dval = 0.;
			dval = va_arg(ap, double);
			printf("%f", dval);
		}
		else if (*p != '%')
		{
			putchar(*p);
		}
		p++;
	}
	va_end(ap);
	return (0);
}

float avergae(int num, ...)
{
	int total = 0;
	va_list ap;
	va_start(ap, num);
	for (int i = 0; i < num; i++)
		total += va_arg(ap, int);
	va_end(ap);
	return (float)total / num;
}


int main()
{
	ft_printf("%c %s %d", 'z', "hello", 16);
	printf("%c %d %f %s \n", 'z', 11, 12.12f, "Hello", 200);
	return (0);
}