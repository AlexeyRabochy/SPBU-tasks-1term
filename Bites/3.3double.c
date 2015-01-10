#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

void print_double(long long int x) {

    int i, mi = 51;
	long long int curr = x;
    char m[53];
    int exp = 0;
    int sign = 0;
    m[52] = 0;
	
	
    sign = ( ( unsigned long long) x >> 63); 

	for(i = 1; i < 12; i++)
	{
	    exp += ((x >> (63 - i)) & 1) * pow(2, 11 - i);
	}	
	exp -=1023;
	
    for (i = 0; i < 64; i++)
	{ 
        if(i < 52) 
		{        
            m[mi] = (curr & 1);
            m[mi--] += '0';
        }
        curr >>= 1; 
    }
	
    for (i = 51; i > 0; i--) 
	{ 
        if (m[i] == '0') 
		{ 
            m[i] = '\0';
        }
        else 
		{
            break;
        }
    }
	printf("(-1)^%d*", sign);
	printf("1.%s", m); 
	printf("*2^%d\n", exp);
	
}                                    

int main() {
    double inputVal;
 
    printf("Enter double number: \n");
    scanf("%lf", &inputVal);

    print_double(*(long long int*) &inputVal);
    system("pause");
    return 0;
}