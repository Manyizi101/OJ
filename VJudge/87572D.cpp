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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int MAXL = 100000+10, MAXN = 100000+10;
struct SuffixArray
{
    struct RadixElement
    {
        int id, k[2];
    } RE[MAXL], RT[MAXL];
    int N, A[MAXL], SA[MAXL], Rank[MAXL], Height[MAXL], C[MAXL];
    void RadixSort()
    {
        int i, y;
        for (y = 1; y >= 0; y--)
        {
            memset(C, 0, sizeof(C));
            for (i = 1; i <= N; i++) C[RE[i].k[y]]++;
            for (i = 1; i < MAXL; i++) C[i] += C[i - 1];
            for (i = N; i >= 1; i--) RT[C[RE[i].k[y]]--] = RE[i];
            for (i = 1; i <= N; i++) RE[i] = RT[i];
        }
        for (i = 1; i <= N; i++)
        {
            Rank[ RE[i].id ] = Rank[ RE[i - 1].id ];
            if (RE[i].k[0] != RE[i - 1].k[0] || RE[i].k[1] != RE[i - 1].k[1])
                Rank[ RE[i].id ]++;
        }
    }
    void CalcSA()
    {
        int i, k;
        RE[0].k[0] = -1;
        for (i = 1; i <= N; i++)
            RE[i].id = i, RE[i].k[0] = A[i], RE[i].k[1] = 0;
        RadixSort();
        for (k = 1; k + 1 <= N; k *= 2)
        {
            for (i = 1; i <= N; i++)
                RE[i].id = i, RE[i].k[0] = Rank[i], RE[i].k[1] = i + k <= N ? Rank[i + k] : 0;
            RadixSort();
        }
        for (i = 1; i <= N; i++)
            SA[ Rank[i] ] = i;
    }
    void CalcHeight()
    {
        int i, k, h = 0;
        for (i = 1; i <= N; i++)
        {
            if (Rank[i] == 1)
                h = 0;
            else
            {
                k = SA[Rank[i] - 1];
                if (--h < 0) h = 0;
                for (; A[i + h] == A[k + h]; h++);
            }
            Height[Rank[i]] = h;
        }
    }
} SA;

int main()
{

}
