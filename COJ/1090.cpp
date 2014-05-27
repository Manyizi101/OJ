#include  <stdio.h>

int main()
{
    double xuefen[5],fenshu[5];
    int i;
    double sum=0,jidian=0;
    for(i=0;i<5;i++)
    {
        scanf("%lf%lf", &xuefen[i], &fenshu[i]);
        if(90<=fenshu[i]&&fenshu[i]<=100)   jidian+=4.0*xuefen[i];
        if(85<=fenshu[i]&&fenshu[i]<=89)   jidian+=3.5*xuefen[i];
        if(80<=fenshu[i]&&fenshu[i]<=84)   jidian+=3.0*xuefen[i];
        if(75<=fenshu[i]&&fenshu[i]<=79)   jidian+=2.5*xuefen[i];
        if(70<=fenshu[i]&&fenshu[i]<=74)   jidian+=2.0*xuefen[i];
        if(65<=fenshu[i]&&fenshu[i]<=69)   jidian+=1.5*xuefen[i];
        if(60<=fenshu[i]&&fenshu[i]<=64)   jidian+=1.0*xuefen[i];
        if(0<=fenshu[i]&&fenshu[i]<=60)   jidian+=0*xuefen[i];
        sum+=xuefen[i];
    }
    printf("%.2lf\n", jidian/sum);
    return 0;
}
