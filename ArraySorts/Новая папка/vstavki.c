//Рабочий Алексей 23.10.2013
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 200001
int main()
{
	int n;
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
	    exit(1);
	}
    
	if(fin == NULL) 
	{
	    printf("Open error.\n");
	    exit(1);
	} 
	 
	fscanf(fin, "%d", &n);
	
	for (i = 0; i < n; i++)
	{
	    fscanf(fin, "%d", &mas[i]);
    }
	
	time = clock();
	
	for (i = 1; i < n; i++)
	{
        j = i;
		
        while(j > 0 && mas[j] < mas[j-1])
        {
		    int buf = mas[j];
			mas[j] = mas[j-1];
			mas[j-1] = buf;
			j--;
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