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

void ft_hex(unsigned long long int n)
{
	if (n >= 16)
	{
		ft_hex(n / 16);
		n %= 16;
	}
	if (n > 9 && n < 16)
		ft_putchar_fd((n % 10) + 97);
	else
		ft_putchar_fd(n + 48);
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
			char *sval;
			sval = va_arg(ap, char *);
			ft_putstr_fd(sval);
		}
		else if (*p == 'p')
		{
			void *pval;
			pval = va_arg(ap, void *);
			ft_putchar_fd('0');
			ft_putchar_fd('x');
			ft_hex(pval);
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

int main()
{
	ft_printf("%p\n", 50);
	int ans = printf("%c", '5');
	printf("\n%d", ans);
	return (0);
}