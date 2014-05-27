#include  <stdio.h>

int main()
{
    int t, n[10], i, j, k;
    scanf("%d", &t);
    for(i=0; i<t; i++)  scanf("%d", &n[i]);
    for(i=0; i<t; i++)
    {
        for(j=0; j<n[i]; j++)
        {
            for(k=0; k<3*n[i]+1; k++)
            {
                printf("6");
            }
            for(k=0; k<n[i]; k++)
            {
                printf(" ");
            }
            for(k=0; k<3*n[i]+1; k++)
            {
                printf("0");
            }
            printf("\n");
        }
        for(j=0; j<n[i]; j++)
        {
            for(k=0; k<n[i]; k++)
            {
                printf("6");
            }
            for(k=0; k<3*n[i]+1; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            for(k=0; k<n[i]+1; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            printf("\n");
        }
        for(j=0; j<n[i]; j++)
        {
            for(k=0; k<3*n[i]+1; k++)
            {
                printf("6");
            }
            for(k=0; k<n[i]; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            for(k=0; k<n[i]+1; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            printf("\n");
        }
        for(j=0; j<n[i]; j++)
        {
            for(k=0; k<n[i]; k++)
            {
                printf("6");
            }
            for(k=0; k<n[i]+1; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("6");
            }
            for(k=0; k<n[i]; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            for(k=0; k<n[i]+1; k++)
            {
                printf(" ");
            }
            for(k=0; k<n[i]; k++)
            {
                printf("0");
            }
            printf("\n");
        }
        for(j=0; j<n[i]; j++)
        {
            for(k=0; k<3*n[i]+1; k++)
            {
                printf("6");
            }
            for(k=0; k<n[i]; k++)
            {
                printf(" ");
            }
            for(k=0; k<3*n[i]+1; k++)
            {
                printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}
