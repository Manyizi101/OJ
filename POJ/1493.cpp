#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAX 100

char tmp[30];
int n;
int space[MAX];
int ans;

int main(int argc, char const *argv[])
{
    while (cin >> n && n != 0)
    {
        memset(space, 0, sizeof(space));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                scanf("%c", &tmp[j]);
                if (tmp[j] == ' ') space[i]++;
            }
            getchar();
        }
        sort(space, space + n);
        ans = 0;
        for (int i = 0; i < n; i++)    ans += space[i] - space[0];
        cout << ans << endl;
    }
    return 0;
}