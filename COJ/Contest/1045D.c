#include  <stdio.h>

int main()
{
    int T, n[101],m[101];
    int i;
    scanf("%d", &T);
    for(i=0;i<T;i++)    scanf("%d%d", &n[i], &m[i]);
    for(i=0;i<T;i++)    printf("%d\n", 1+(n[i]-m[i])*(m[i]-1));
    return 0;
}
