#include <iostream>
#include <string>

using namespace std;

const int SIZE = 999;
int dp[SIZE][SIZE] = {0};

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(int argc, char const *argv[])
{
    int len1, len2;
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        len1 = str1.length();
        len2 = str2.length();
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[len1][len2] << endl;
    }
    return 0;
}