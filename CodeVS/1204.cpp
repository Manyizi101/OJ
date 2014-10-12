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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

char text[110],pattern[110];
/*
* @brief 计算部分匹配表，即 next 数组.
*
* @param[in] pattern 模式串
* @param[out] next next 数组
* @return 无
*/
void compute_prefix(const char *pattern, int next[])
{
    int i;
    int j = -1;
    const int m = strlen(pattern);
    next[0] = j;
    for (i = 1; i < m; i++)
    {
        while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[i] == pattern[j + 1]) j++;
        next[i] = j;
    }
}
/*
* @brief KMP 算法.
*
x
《算法》，Robert Sedgewick，人民邮电出版社，http://book.douban.com/subject/10432347/
8 第 3 章 字符串
* @param[in] text 文本
* @param[in] pattern 模式串
* @return 成功则返回第一次匹配的位置，失败则返回-1
*/
int kmp(const char *text, const char *pattern)
{
    int i;
    int j = -1;
    const int n = strlen(text);
    const int m = strlen(pattern);
    if (n == 0 && m == 0) return 0; /* "","" */
    if (m == 0) return 0; /* "a","" */
    int *next = (int *)malloc(sizeof(int) * m);
    compute_prefix(pattern, next);
    for (i = 0; i < n; i++)
    {
        while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
        if (text[i] == pattern[j + 1]) j++;
        if (j == m - 1)
        {
            free(next);
            return i - j;
        }
    }
    free(next);
    return -1;
}

int main(int argc, char const *argv[])
{
	scanf("%s%s", text,pattern);
    char *ch = text;
    int i = kmp(text, pattern);
    if (i >= 0) printf("%d", i+1);
    return 0;
}