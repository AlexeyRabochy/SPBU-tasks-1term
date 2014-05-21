//Алексей Рабочий 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void print_float(int x) {

    int i, mi = 22, msum = 0, curr = x;
    char m[24];
    int uex = 0;
    int sign;
    m[23] = 0;
    
    sign = ( ( unsigned int) x >> 31); 
    uex = ( ( (unsigned int) x >> 23) & ( (1 << 8) - 1) ); 
    for (i = 0; i < 32; i++) 
	{ 
        if(i < 23) 
		{        
            m[mi] = (curr & 1); 
            msum += m[mi]; 
            m[mi--] += '0';
        }
        curr >>= 1;
    }
	
    for (i = 22; i > 0; i--) 
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
 	uex -= 127; 
	printf("(-1)^%d*", sign);
	
    if ((uex== -127) && (m != 0)) 
	{
		printf("0.");
	}
	else
	{
		printf("1.");
	}
   
	printf("%s", m); 
	printf("*2^%d\n", uex);
	
}                                    

int main() {
    float inputVal;
 
    printf("Enter float number: \n");
    scanf("%f", &inputVal);

    print_float(*((int*)&inputVal) );
    system("pause");
    return 0;
}