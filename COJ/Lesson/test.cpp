#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 10 + 10;

int a[MAXN];

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 8; i++)
	{
		scanf("%d,", &a[i]);
	}
	scanf("%d%d", &a[8], &a[9]);
	qsort(a,10,sizeof(a[0]),cmp);
	for (int i = 0; i < 9; i++)
	{
		printf("%d,", a[i]);
	}
	printf("%d", a[9]);
	return 0;
}