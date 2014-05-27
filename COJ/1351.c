#include   <stdio.h>

int main()
{
    int X1,X2,Y1,Y2,r1,r2;
    while(scanf("%d%d%d%d%d%d", &X1,&Y1,&r1,&X2,&Y2,&r2) != EOF)
    {
        if(((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))==(r1-r2)*(r1-r2))  printf("1");
        if(((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))>(r1+r2)*(r1+r2))  printf("2");
        if(((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))<(r1-r2)*(r1-r2))  printf("3");
        if(((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))<(r1+r2)*(r1+r2)&&((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2))>(r1-r2)*(r1-r2))  printf("4");
    }
    return 0;
}
