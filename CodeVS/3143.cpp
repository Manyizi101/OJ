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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 16+10

int n;

typedef struct BinNode
{
    BinNode* left;
    BinNode* right;
    int value;
} BinNode;

typedef BinNode* bintree;

void preorder(bintree t)
{
    if(t)
    {
        printf("%d", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}

void midorder(bintree t)
{
    if(t)
    {
        preorder(t->left);
        printf("%d", t->value);
        preorder(t->right);
    }
}

void nextorder(bintree t)
{
    if(t)
    {
        preorder(t->left);
        preorder(t->right);
        printf("%d", t->value);
    }
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
    {

    }
	return 0;
}
