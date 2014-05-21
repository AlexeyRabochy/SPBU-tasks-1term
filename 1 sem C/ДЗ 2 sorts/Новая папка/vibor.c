//Рабочий Алексей 23.10.2013
#include <stdio.h>
#include <time.h>
#define N 200001
int main()
{
	int n, temp = 0, buf;
	int i = 0, j = 0;
	int mas[N];
	clock_t time;
	
	FILE *fin;
	FILE *fout;
	
	fin = fopen("100000sorted.txt", "r");
	fout = fopen("res.txt", "w");
	
	if(fout == NULL) 
	{
	    printf("Open error\n");
	    system("pause");
	}
    
	if(fin == NULL) 
	{
	    printf("Open error.\n");
	    system("pause");
	} 
	
	fscanf(fin, "%d", &n);
	
	for (i = 0; i < n; i++)
	{
	    fscanf(fin, "%d", &mas[i]);
    }
	
	
	time = clock();
	

    for (i = 0; i < n; i++) 
	{
        int min = i;
 
        for(j = i + 1; j < n; j++) 
		{
            if(mas[j] < mas[min])
			{
                    min = j;
            }
        }
		if (min != i) 
		    {
                buf = mas[i];
                mas[i] = mas[min];
                mas[min] = buf;
		    }   
	}	
	time = clock() - time;
	
	for (i = 0; i < n; i++)
	{
		fprintf(fout, "%d\n", mas[i]);
	}
	
	fprintf(fout, "%f", (double)time/CLOCKS_PER_SEC);
	fclose(fin);
	fclose(fout);	
}	
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 