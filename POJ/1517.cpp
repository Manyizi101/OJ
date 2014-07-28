#include <iostream>
#include <cstdio>
using namespace std;

double ans = 2.5;
double mulit = 1;

int main(int argc, char const *argv[])
{
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for (int i = 3; i < 10; i++)
    {
        mulit = 1;
        for (double j = 1; j <= i; j++)
        {
            mulit *= j;
        }
        ans += 1 / mulit;
        printf("%d %.9lf\n", i , ans);
    }
    return 0;
}