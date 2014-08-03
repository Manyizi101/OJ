#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int s[10005];
int n;

void multiply()
{
    int i , j;
    memset(s, 0, sizeof(s));
    s[1] = 1;
    j = 1;
    for (i = 2; i <= 10000; i++)
    {
        j *= i;
        while (j % 10 == 0)
            j /= 10;
        j %= 100000;
        s[i] = j % 10;
    }
}

int main(int argc, char const *argv[])
{
    multiply();
    while (cin >> n)
    {
        printf("%5d", n);
        cout << " -> " << s[n] << endl;
    }
    return 0;
}