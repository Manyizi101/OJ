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
#define inf (1<<30)
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned int trees;
    int i, j;
    int M;
    unsigned int start, end;

    while (scanf("%u%d", &trees, &M), trees != 0 || M != 0)
    {
        trees += 1;
        for (i = 0; i < M ; i++)
        {
            scanf("%u%u", &start, &end);
            trees -= end - start + 1;
        }
        printf("%u\n", trees);
    }
    return 0;
}
