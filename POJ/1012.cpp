#include <iostream>
using namespace std;

int r[14];
int i, j, k;

bool solve(int k, int i)
{
    int n = k * 2, m = i, x = 0;
    while (n > k)
    {
        x = (x + m - 1) % n;
        if (x < k) return false;
        n--;
    }
    return true;
}

int main()
{
    for (k = 1; k < 14; k++)
    {
        for (i = k + 1;; i += k + 1)
        {
            if (solve(k, i))
            {
                r[k] = i;
                break;
            }
            else if (solve(k, i + 1))
            {
                r[k] = i + 1;
                break;
            }
        }
    }

    while (cin >> k, k)
    {
        cout << r[k] << endl;
    }
    return 0;
}