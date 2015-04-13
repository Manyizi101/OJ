#include <stdio.h>
#include <stdlib.h>

int a[11];

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void init()
{
	for(int i=0;i<8;i++)
	{
		scanf("%d,", &a[i]);
	}
	scanf("%d", &a[8]);
	scanf("%d", &a[9]);
}

int main(int argc, char const *argv[])
{
	init();
	qsort (a, 10, sizeof(int), cmp);
	for(int i=0;i<9;i++)
	{
		printf("%d,", a[i]);
	}
	printf("%d", a[9]);
	return 0;
}