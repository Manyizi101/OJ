#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, i, sum, ave, j, ans, t = 1;
    int e[51];
    while (scanf("%d", &n) == 1 && n)
    {
        ave = sum = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &e[i]);
            sum += e[i];
        }
        ave = sum / n;
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            if (e[i] > ave)
            {
                ans += e[i] - ave;
            }
        }
        cout << "Set #" << t++ << "\nThe minimum number of moves is " << ans << "." << endl << endl;
    }
    return 0;
}