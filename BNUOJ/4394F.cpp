#include<stdio.h>
using namespace std;

int a, b;

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &a, &b) && (a != 0 || b != 0))
    {
        if (a * b % 2 == 0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}