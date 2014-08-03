#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, x, y;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d%d", &x, &y);
        if (x < 0 || y < 0)
            printf("No Number\n");
        else if (x == y || x == y + 2)
            printf("%d\n", x % 2 ? (x + y - 1) : (x + y) );
        else
            printf("No Number\n");
    }
    return 0;
}