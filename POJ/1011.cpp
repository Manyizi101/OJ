#include <iostream>

using namespace std;

int n;
int stick[100];
int sum, big;
int i;
int ans;

int main(int argc, char const *argv[])
{
    while (cin >> n && n != 0)
    {
        sum = big = 0;
        for (i = 0; i < n; i++)
        {
            cin >> stick[i];
            sum += stick[i];
            if (stick[i] > big)    big = stick[i];
        }
        for (i = 1; i <= n; i++)
        {
            if (sum % i == 0 && sum / i >= big)    ans = i;
        }
        cout << sum / ans << endl;
    }
    return 0;
}