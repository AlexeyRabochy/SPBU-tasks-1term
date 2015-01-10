#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void oops()
{
    printf("OOPS!");	
}

int input()
{
    int m[3];
    int i = 0;
	scanf("%d", &m[7]);
	
}

int main()
{
    
    printf("oops = %d input = %d\n", &oops, &input);
	input();
	return 0;
}
	
	
	