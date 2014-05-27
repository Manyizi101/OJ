#include   <stdio.h>
#include   <math.h>


int main()
{
    int T ,i = 0;
    double S , MianJi;
    double A[210], B[210], C[210];
    scanf("%d", &T);
    for (i = 0; i < T; i++)     scanf("%lf%lf%lf", &A[i], &B[i], &C[i]);
    for (i = 0; i < T; i++)
    {
        S = (A[i] + B[i] + C[i])/2.0;
        MianJi = sqrt(S*(S-A[i])*(S-B[i])*(S-C[i]));
        printf("%.3f\n", MianJi);
    }
    return 0;
}
