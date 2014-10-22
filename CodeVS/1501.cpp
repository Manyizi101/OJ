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
#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 16+10

int n;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pSelf;
}position[MAXN];

void init()
{
    position[0].m_pLeft=NULL;
    position[0].m_pRight=NULL;
    position[0].m_pSelf=position[0].m_pSelf;
    int left,right;
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        position[i].m_pSelf=position[i].m_pSelf;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d%d", &left, &right);
        position[i].m_pLeft=position[left].m_pSelf;
        position[i].m_pRight=position[right].m_pSelf;
    }
}

int GetNodeNum(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL) // 递归出口
		return 0;
	return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1;
}

int GetDepth(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL) // 递归出口
		return 0;
	int depthLeft = GetDepth(pRoot->m_pLeft);
	int depthRight = GetDepth(pRoot->m_pRight);
	return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
}

int GetLeafNodeNum(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL)
		return 0;
	if(pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL)
		return 1;
	int numLeft = GetLeafNodeNum(pRoot->m_pLeft); // 左子树中叶节点的个数
	int numRight = GetLeafNodeNum(pRoot->m_pRight); // 右子树中叶节点的个数
	return (numLeft + numRight);
}

int main()
{
    init();
    printf("%d %d\n", GetLeafNodeNum(position), GetDepth(position));
    return 0;
}
