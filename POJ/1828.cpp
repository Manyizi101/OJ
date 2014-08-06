#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point
{
    int x; int y;
    int flag;
}p[50050];
int n;

int cmp( const void *a , const void *b )
{
    struct Point *c = (Point *)a;
    struct Point *d = (Point *)b;
    if (c->x != d->x) return c->x - d->x;
    else return c->y - d->y;
}

int main()
{

    while (scanf("%d", &n) != EOF && n)
    {
        int counter = 1;
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i)
        {
            printf("%d%d", &p[i].x, &p[i].y);
        }
        qsort(p, n, sizeof(p[0]), cmp
             );
        int max = p[n - 1].y;
        for (int i = n - 2; i >= 0; --i)
        {
            if (p[i].y > max)
            {
                counter++;
                max = p[i].y;
            }
        }
        printf("%d\n", counter);
    }

}