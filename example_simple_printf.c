#include <stdio.h>
#include <stdarg.h>

void f_b(char *apFormat, ...)
{
	va_list ap;
	char *p;

	va_start(ap, apFormat);
	p = apFormat;
	while (*p)
	{
		if (*p == 'd')
		{
			int ival = 0;
			ival = va_arg(ap, int);
			printf ("%d ", ival);
		}
		else if (*p == 'f')
		{
			double  dval = 0.;
			dval = va_arg(ap, double);
			printf("%f ", dval);
		}
		else if (*p == 's')
		{
			for(char *sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
		}
		else if (*p != '%')
		{
			putchar(*p);
		}
		p++;
	}
	va_end(ap);
}

void example_b()
{
	f_b("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
}

int main()
{
	example_b();

	return (0);
}