#include  <stdio.h>
#include  <stdlib.h>
#include   <math.h>

double cal(int a, int b)
{
    double ha,hb;
    if(a>12)    ha = (a-12)/12.0*360.0;
    if(a<=12)   ha = a/12.0*360.0;
    hb = b/60.0*360.0;
    if(ha-hb>180)   return 360.0-ha+hb;
    if(ha>hb&&ha-hb<=180)    return ha-hb;
    if(hb-ha>180)  return 360.0-hb+ha;
    if(ha<=hb&&hb-ha<=180)   return hb-ha;
}

void dchange(double *a, double *b)
{
    double tmp;
    tmp=*a; *a=*b; *b=tmp;
}

void ichange(int *a,int *b)
{
    int tmp;
    tmp = *a; *a = *b; *b= tmp;
}

int main()
{
    int n,i,j,hour[5],minute[5];
    double degaree[5];
    scanf("%d", &n);
    while(n--)
    {
        for(i=0;i<5;i++)
        {
            scanf("%d:%d", &hour[i], &minute[i]);
            degaree[i] = cal(hour[i], minute[i]);
        }
        for(i=0;i<5;i++)
        {
            for(j=4;j>i;j--)
            {
                if(degaree[i]>degaree[j])
                {
                    dchange(&degaree[i], &degaree[j]);
                    ichange(&hour[i],&hour[j]);
                    ichange(&minute[i],&minute[j]);
                }
                if(degaree[i]==degaree[j]&&hour[i]>hour[j])
                {
                    dchange(&degaree[i], &degaree[j]);
                    ichange(&hour[i],&hour[j]);
                    ichange(&minute[i],&minute[j]);
                }
            }
        }

        printf("%02d:%02d\n", hour[2], minute[2]);
    }
    return 0;
}
