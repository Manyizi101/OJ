#include  <stdio.h>
#include  <math.h>

int main()
{
    int n,a[50],b[50],c[50];
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        c[i] = ceil(a[i]*0.3+b[i]*0.7);
    }
    for(i=0;i<n;i++)
    {
        if(c[i]>=60)    printf("%d\n", c[i]);
        if(c[i]>=55&&c[i]<60&&a[i]<=75)
        {
            printf("60\n");
            printf("You are so lucky!\n");
        }
        if(c[i]<55)
        {
            printf("Sorry,you have not passed the exam.\n");
        }
    }
    return 0;

}
