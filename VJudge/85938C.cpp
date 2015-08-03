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

const int maxn = 30;

char preOrder[maxn], midOrder[maxn];

struct node
{
    char c;
    node *left;
    node *right;
    node(char c)
    {
        this->c = c;
        this->left = left;
        this->right = right;
    }
};

node *root;

node* createTree(char *pre, char *mid, int len)
{
    if (len == 0)  return NULL;
    int k = 0;
    while (mid[k] != pre[0])   k++;
    node *root = new node(pre[0]);
    root->left = createTree(pre + 1, mid, k);
    root->right = createTree(pre + k + 1, mid + k + 1, len - k - 1);
    return root;
}

void output(node *u)
{
    if (u != NULL)
    {
        output(u->left);
        output(u->right);
        printf("%c", u->c);
    }
}

void solve()
{
    int len = strlen(preOrder);
    root = createTree(preOrder, midOrder, len);
    output(root);
    puts("");
}

int main()
{
    while (~scanf("%s", preOrder))
    {
        scanf("%s", midOrder);
        solve();
    }
    return 0;
}