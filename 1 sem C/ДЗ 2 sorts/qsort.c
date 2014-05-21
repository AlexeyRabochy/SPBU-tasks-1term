#include <stdio.h>
#include <time.h>
#define N 200001

int qs(int* mas, int left, int right)
{
    int j = right, i = left, p = mas[(left+right/2)];

    do
	{ 
	    while (mas[i] < p) i++;
        while (mas[j] > p) j--;
 
        if (i < j)
        {
			int buf = mas[i];
			mas[i] = mas[j];
			mas[j] = buf;
            i++;
            j--;
		}
        
    }
	while (i <= j);
 
    if (i < right)
        qs(mas, i, right);
    if (left < j)
        qs(mas, left,j);
}	

int main()
{
	int n;
	int i = 0, j = 0;
	int mas[N];
	clock_t time;
	
	FILE *fin;
	FILE *fout;
	
	fin = fopen("5000rand.txt", "r");
	fout = fopen("res.txt", "w");
	
	fscanf(fin, "%d", &n);
	
	for (i = 0; i < n; i++)
	{
	    fscanf(fin, "%d", &mas[i]);
    }
	
	time = clock();
	
	qs(mas, 0, n);
	
	time = clock() - time;
	
	for (i = 0; i < n; i++)
	{
		fprintf(fout, "%d\n", mas[i]);
	}
	
	fprintf(fout, "%f", (double)time/CLOCKS_PER_SEC);
	fclose(fin);
	fclose(fout);
}

	
	