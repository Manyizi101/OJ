#include  <stdio.h>
#include  <iostream>
#include  <algorithm>
#define   MAX  100000
using namespace std;

struct student
{
    char number[6],name[8];
    int grade;
};

int main()
{
    int N, C;
    while(scanf("%d%d", &N,&C)&&N!=0)
    {
        int i;
        student a[MAX];
        for(i=0; i<N; i++)    scanf("%s%s%d", a[i].number, a[i].name, &a[i].grade);
        if(C==1)
        {
            sort(a[0].number,a[N-1].number);
            for(i=0;i<N;i++)    printf("%s", a[i].number);
        }
        if(C==2)
        {
            sort(a[0].name,a[N-1].name);
        }
        if(C==3)
        {
            sort(a[0].grade,a[N-1].grade);
        }
    }
}
