#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int dig[1010][1010];

int main(int argc, char const *argv[])
{
    dig[1][0] = 0;
    dig[2][0] = 1;

    for (int i = 3; i <= 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dig[i][j] += dig[i - 2][j] * 2 + dig[i - 1][j];
            if (dig[i][j] > 9)
            {
                dig[i][j + 1] = dig[i][j] / 10;
                dig[i][j] %= 10;
            }
        }
    }

    int n;
    while ( cin >> n)
    {
        if ( n == 1) cout << "0" << endl;
        else
        {
            bool flag = true;
            for (int i = 999; i >= 0; i--)
            {
                if ( dig[n][i] && flag)
                {
                    flag = false;
                }
                if (!flag)
                    cout << dig[n][i] ;
            }
            cout << endl;
        }
    }
    return 0;
}