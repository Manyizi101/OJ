#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

long long a;

void bfs()
{
    queue<long long>q;
    int i, j;
    long long x = 1, pos;
    q.push(x);
    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        for (i = 0; i < 2; i++)
        {
            x = pos * 10 + i;
            if (x % a == 0)
            {
                cout << x << endl;
                return;
            }
            q.push(x);
        }
    }
}

int main(int argc, char const *argv[])
{
    int i, j;
    while (cin >> a && a)
    {
        if (a == 1)
        {
            cout << "1" << endl;
            continue;
        }
        bfs();
    }
    return 0;
}