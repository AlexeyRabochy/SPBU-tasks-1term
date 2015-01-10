// Алексей Рабочий 1.11.2013
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 200001 

void qs(int m[], int left, int right)
{
	int x = 0, i1 = 0, j1 = 0;
	if (left >= right - 1)// если остался 1 элемент
	{
		return;
	}
    else
	{
	    x = m[left + ((right - left) / 2)]; // выбираем средний
	    i1 = left;
	    j1 = right;

	    while (i1 <= j1) // до 
	    {
		    while (m[i1] < x)
		    {
		    	i1++;
		    }
		    while (m[j1] > x)
		    {
			    j1--;
		    }
		    if (i1 <= j1)
		   {
			    int buf = m[i1];
			    m[i1] = m[j1];
			    m[j1] = buf;
			    i1++;
			    j1--;
		    }
	    } 	
	}	
	if (i1 < right)
	{
		qs(m, i1, right);
	}
	if (j1 > left)
	{
		qs(m, left, j1);
	}
	
}

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

	qs(mas, 0, n-1);

	time = clock() - time;

	for (i = 0; i < n; i++)
	{
	    fprintf(fout, "%d\n", mas[i]);
	}

	fprintf(fout, "%f", (double)time/CLOCKS_PER_SEC);

	fclose(fin);	
	fclose(fout);
}
