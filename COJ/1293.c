#include   <stdio.h>
#include   <string.h>


int main()
{
    char A[10], B[10];
    int i, j, la, lb;
    long long int ans = 0;
    scanf("%s%s", &A, &B);
    la = strlen(A);
    lb = strlen(B);
    for(i = 0; i < la; i++)
    {
        for (j = 0; j < lb; j++)
        {
            ans += (A[i]-48) * (B[j]-48);
        }
    }
    printf("%lld", ans);
    return 0;
}
