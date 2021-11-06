#include <stdio.h>
#include <stdarg.h>
void f_a(int aCount, ...)
{
	int value = 0;
	va_list ap; //будет указывать по очереди на каждый из аргументов
	va_start(ap, aCount); //инициализирует vl указателем на следующие данные после последнего фактического параметра
	//в нашем случае aCount
	int i = 0;
	//проходимся в цикле и пытаемся извлечь все aCount аргументы
	while (i < aCount)
	{
		value = va_arg(ap, int);//на каждом вызове выдаёт очередной аргумент
		printf("%i ", value);
		i++;
	}
	va_end(ap);//очищает
	printf("\n");
}

void example_a()
{
	f_a(3, 1, 2, 3);
	f_a(5, 1, 2, 3, 123, 543543);
}

int main()
{
	example_a();
	return (0);
}