#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char coin[12];
int real[12];

string balance(string left, string right, string match)
{
    if (match.compare("even"))
    {
        for (int i = 0; i < 12; i++)
        {
            if (left.find(coin[i]) != -1 && right.find(coin[i]) != -1)
            {
                real[i] = 1;
            }
        }
    }
}

int main()
{
    int n, i, flag;
    for (i = 0; i < 12; i++)   coin[i] = 'A' + i;
    cin >> n;
    while (n--)
    {
        memset(real, 0, sizeof(real));
        for (int j = 0; j < 3; j++)
        {
            string left, right, match;
            cin >> left;
            getchar();
            cin >> right;
            getchar();
            cin >> match;
            balance(left, right, match);
            if (match.compare("up"))
                flag = 1;
            else if (match.compare("down"))
                flag = 2;
        }
    }
}