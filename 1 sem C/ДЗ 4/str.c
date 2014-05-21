//Алексей Рабочий 14.11.2013 "Функции str"
#include <stdio.h>

int strlen(char *s)
{
    int i = 0;

    while (s[i] != 0)
    {
        i++;
    }
    return i;
}

int strcpy(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != 0)
    {
        s2[i] = s1[i];
        i++;
    }

    s2[i] = 0;
}

int strcmp(char *s1, char *s2)
{
    int i = 0;

    while(*s1 && *s2 && *s1 == *s2){
	  ++s1;
	  ++s2;
	}
	
	return *s1 - *s2;
	
}

int main()
{
    char str1[100], str2[100], str3[100];
	
	gets(str1);
	gets(str2);
	
	printf("str1len = %d\n", strlen(str1));
	printf("str2len = %d\n", strlen(str2));
	
	strcpy(str1, str3);
    printf("str3 = str1 = %s\n", str3);
	
	printf("str1 = str2?%d", strcmp(str1, str2));
	    
}	

	




















