//Алексей Рабочий 07.11.2013 
#include <stdio.h>
#define N 100000

int f(int n)
{
    int x = n & 1;
	return x;
}	

int main()
{
    int mas[N];
    int o = 0, i = 0;
	int num;
    
	scanf("%d", &num);
	
    unsigned int n1 = (unsigned int) num;
	
    while (n1 != 0)
    {
	    mas[o] = f(n1);
		n1 = n1/2;
		o++;
	}	
	for (i = 0; i < o/2; i++)
	{
	    int buf = mas[i];
		mas[i] = mas[o-1-i];
		mas[o-i] = buf;
	}	
	
	
	for (i = 0; i < o; i++)
	{
	printf("%d", mas[i]);
    }

    system("pause");
}