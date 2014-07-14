#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int prime[36] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};
int n;
int facter[5010];
int input[5010];
int flag;
int ans = 1;

int main(int argc, char const *argv[])
{
    memset(facter, 0, sizeof(facter));
    memset(input, 0, sizeof(input));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        for (int j = 0; j < 36; j++)
        {
            if (input[i] % prime[j] == 0)   facter[i] = prime[j];
        }
    }
    flag = 0;
    ans = input[0];
    for (int i = 0; i < n; i++)
    {
        if (facter[i] > facter[flag])
        {
            ans = input[i];
            flag = i;
        }
    }
    cout << ans;
    return 0;
}