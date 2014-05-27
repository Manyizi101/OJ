#include   <stdio.h>


int main()
{
    int a1, a2, a3, b1, b2, b3, c1, c2 ,c3, Ans;
    scanf("%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3);
    Ans = a1*b2*c3+a2*b3*c1+a3*b1*c2-a1*b3*c2-a2*b1*c3-a3*b2*c1;
    printf("%d", Ans);
    return 0;
}
