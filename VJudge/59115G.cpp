#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

#define MAX 100000+10

int F[MAX];

void kmp_init(string &P)
{
    F[0] = 0;  F[1] = 0;
    int i = 1, j = 0;
    while (i < P.size())
    {
        if (P[i] == P[j])
            F[++i] = ++j;
        else if (j == 0)
            F[++i] = 0;
        else
            j = F[j];
    }
}

int kmp(string &P, string &T)
{
    kmp_init(P);
    int i = 0, j = 0;
    int n = T.size(), m = P.size();
    while (i < n)
    {
        while (j < m)
        {
            if (P[j] == T[i])
            {
                i++; j++;
            }
            else break;
        }
        if (j == 0) i++;
        if (i == n) return j;
        j = F[j];
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    string S, P, T;
    while (cin >> S)
    {
        P = string(S.rbegin(), S.rend());
        string K = S.substr(0, S.size() - kmp(P, S));
        cout << S + string(K.rbegin(), K.rend()) << endl;
    }
}