//Alex Rabochy Hashmap 13.02.2014
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXINT 2147483647
#define MOD 77373
int maxChain = 0;
int minChain = 2147483647;
int medChain = 0;
int p = 0;
int cntChain = 0;


typedef struct Map
{
	char *key;
	int count;
}Map;

int makeHash(char *w)
{
	int p = 73, cnt = 0, i = 0, mod = MOD;
	int hash = 0;
	cnt = strlen(w);
	for (i = 0; i < cnt; i++)
	{
		hash = (hash * p + w[i] - 'a' + 1) % mod;
	}
	return hash;
}

int check_C(int x)
{
	if (x >= 'a' && x <= 'z')
	{
		return x;
	}
	else if (x >= 'A' && x <= 'Z')
	{
		return x - 'A' + 'a';
	}
	else
	{
		return 0;
	}
}

void add(Map *map, char *w)
{
	int i = 0, max = 0, j = 0;
	int hash = makeHash(w);
	char *word = (char*)malloc(sizeof(char)* strlen(w) + 1);
	strcpy(word, w);

	if (strcmp(word, map[hash].key) == 0)
	{
		map[hash].count++;
	}
	else
	{
		while (strcmp(word, map[hash + i].key) != 0 && strcmp(map[hash + i].key, "$") != 0)
		{
			i++;
			j++;
			
		}
		p = p + j;
		cntChain++;

		if (j > maxChain)
		{
			maxChain = j;
		}
		if (j < minChain && j >= 1)
		{
			minChain = j;
		}

		j = 0;
		map[hash + i].key = word;
		map[hash + i].count++;
	}

}

void print(Map *map)
{
	int med = 0, cntw = 0, max = 0, min = MAXINT, lmax = 0;
	char *wmax = "s", *wmin = "s", *lmaxw = "s";
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		if (strcmp(map[i].key, "$") != 0)
		{
			cntw++;

			if (strlen(map[i].key) > max)
			{
				max = strlen(map[i].key);
				wmax = map[i].key;
			}

			if (strlen(map[i].key) < min)
			{
				min = strlen(map[i].key);
				wmin = map[i].key;
			}

			if (map[i].count > lmax)
			{
				lmax = map[i].count;
				lmaxw = map[i].key;
			}

			med = med + strlen(map[i].key);
			printf("%s ", map[i].key);
			printf("%d\n", map[i].count);

		}


	}

	med = med / cntw;
	printf("\n");
	printf("the most frequent word is \"%s\" - %d\n", lmaxw, lmax);
	printf("the shotest word is \"%s\" - %d\n", wmin, min);
	printf("the longest word is \"%s\" - %d\n", wmax, max);
	printf("average length = %d\n", med);
}

int main()
{
	FILE* input;

	Map map[100000];
	int c, count = 0, kol = 0, i = 0;
	char *w;

	input = fopen("in.txt", "r");

	c = fgetc(input);

	for (i = 0; i < 100000; i++)
	{
		map[i].key = "$";
		map[i].count = 0;
	}

	while (c != EOF)
	{
		c = check_C(c);
		if (c)
		{
			if (count == 0)
			{
				w = (char*)(malloc(sizeof(char)));
				w[count] = c;
			}
			else
			{
				w = (char*)realloc(w, sizeof(char)*(count + 1));
				w[count] = c;
			}
			count++;
		}
		else if (count != 0)
		{
			w = (char*)realloc(w, sizeof(char)*(count + 1));
			w[count] = 0;
			add(map, w);
			++kol;
			free(w);
			count = 0;
		}
		c = fgetc(input);
	}
	print(map);
	printf("the longest chain = %d\n", maxChain);
	printf("the shotest chain = %d\n", minChain);
	printf("the average chain = %d\n", p / cntChain);
	system("pause");
	return 0;
}












