#include <cstdio>
#include <cstring>
const int M = 1001000;
char str[M];
int p[M];
char s[M];
int n;
void checkmax(int &ans, int b)
{
    if (b > ans) ans = b;
}
inline int min(int a, int b)
{
    return a < b ? a : b;
}
void kp()
{
    int i;
    int mx = 0;
    int id;
    for (i = 1; i < n; i++)
    {
        if ( mx > i )
            p[i] = min( p[2 * id - i], p[id] + id - i );
        else
            p[i] = 1;
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++) ;
        if ( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}
void pre()
{
    int i, j, k;
    n = strlen(s);
    str[0] = '$';
    str[1] = '#';
    for (i = 0; i < n; i++)
    {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    str[n] = 0;
}

void pt()
{
    int i;
    int ans = 0;
    for (i = 0; i < n; i++)
        checkmax(ans, p[i]);
    printf("%d\n", ans - 1);
}

int main()
{
    int T, _ = 0;
    int n;
    scanf("%d", &n);
    while (n--)
    {
    	getchar();
        scanf("%s", s);
        pre();
        kp();
        pt();
    }
    return 0;
}