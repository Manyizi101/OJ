#include  <Stdio.h>
#include  <math.h>

int main()
{
    int a,i;
    while(scanf("%d", &a)!=EOF)
    {
        for(i=1;;i++)
        {
            if(((pow(10,i)-1)/9)%a)
            {
                printf("%d\n", i);
                break;
            }
            continue;
        }
    }
    return 0;
}
