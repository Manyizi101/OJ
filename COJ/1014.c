#include   <stdio.h>
#include   <math.h>


int main()
{
    int T = 0, i = 0, j = 0;
    int S[100] = {0};
    double answer1 , answer2 = 0;
    scanf("%d", &T);
    for ( i = 0; i < T; i++)
    {
        for (j = 0; j < 5; j++)   scanf("%d", &S[j]);
        answer1 = (S[0] + S[1] + S[2] + S[3] + S[4])/5.0;
        answer2 = sqrt(((S[0]-answer1)*(S[0]-answer1)+(S[1]-answer1)*(S[1]-answer1)+(S[2]-answer1)*(S[2]-answer1)+(S[3]-answer1)*(S[3]-answer1)+(S[4]-answer1)*(S[4]-answer1))/5.0);
        printf("%.3f %.3f\n", answer1, answer2);
    }
    return 0;
}
