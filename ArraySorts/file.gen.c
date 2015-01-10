#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	FILE *f;
	f = fopen("SM50inv.txt", "w");

	for (i = 50; i > 0; i--)
	{
		fprintf(f, "%d\n", i);
	}
	fclose(f);
}