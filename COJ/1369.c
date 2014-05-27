#include   <stdio.h>


int main()
{
    int i = 0 , j = 0;
    int a[100];
    char b[100];
    while (scanf("%d", &a[i]) != EOF)       i++;
    for (j = 0; j < i; j++)     b[j] = (char)(a[i]);
    printf("%s", b);
    return 0;
}
