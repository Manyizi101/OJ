#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

char *num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(int argc, char const *argv[])
{
    int n = 0, i = 0;
    int str[20], len = 0;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        len = 0;
        if (a[i] == 0)
        {
            str[0] = 0;
            len = 1;
        }
        while ( a[i] != 0 )
        {
            str[len++] = a[i] % 10;
            a[i] /= 10;
        }
        while (len > 0)
        {
            printf("%s ", num[str[--len]]);
        }
        printf("\n");
    }
}