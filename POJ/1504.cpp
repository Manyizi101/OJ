#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n;
string a, b;
char c[100];
int i;
int ans;

int main(int argc, char const *argv[])
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (a.length() < b.length())   a.swap(b);
        for (i = 0; i < a.length() + 1; i++) c[i] = '0';
        ans = 0;
        for (i = 0; i < b.length(); i++)
        {
            c[i] += a[i] + b[i] - 3 * '0';
            if (c[i] >= 10)
            {
                c[i + 1]++;
                c[i] = c[i] - 10 + '0';
            }
            else
                c[i] = c[i] + '0';
        }
        for (i = b.length(); i < a.length(); i++)
        {
            c[i] += a[i] - 2 * '0';
            if (c[i] >= 10)
            {
                c[i + 1]++;
                c[i] = c[i] - 10 + '0';
            }
            else
                c[i] = c[i] + '0';
        }
        for (i = 0; i <= a.length(); i++)
        {
            ans = ans * 10 + c[i] - '0';
        }
        if (ans % 10 == 0)   ans /= 10;
        printf("%d\n", ans);
    }
    return 0;
}