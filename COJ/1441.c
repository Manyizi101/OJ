#include   <stdio.h>


int main()
{
    int m, n, money = 0;
    scanf("%d%d", &n, &m);
    if (n%3==0)     money += n/3;
    else    money += n/3+1;
    if (m <= 60)    money += 4*m;
    if (m > 60)     money += 240+(m-60)*8;
    printf("%d", money);
    return 0;
}
