// Алексей Рабочий 14.11.2013 "Умножение двух целых чисел"
#include <stdio.h>
#include <math.h>

int main()
{
	int a, res;
	int i = 0;
	double b;

	printf("Enter the first factor\n");
	scanf("%d", &a);
	printf("Enter the second factor\n");
	scanf("%lf", &b);

	double k1 = sqrt(b);
	int k = (int)k1; 

	if (k == k1) // если число является степенью двойки
	{

		res = a << k;
	}
	else
	{
		double st = log(b) / log(2.0); //степень двойки
		int n = (int)st; // преобразовываю double в int так как сдвигать можно только на целое число
		res = a << n; //умножаем на степень двойки
		int p = powf(2, n);
		for (i = p + 1; i <= b; i++) // добавляем отсальное
		{
			res = res + a;
		}

	}

	printf("%d\n", res);
}