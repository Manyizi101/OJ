#include  <cstdio>
using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    if((a%4!=0)||(a%100==0&&a%400!=0))    printf("N\n");
    else printf("Y\n");
    return 0;
}
