
#include  <cstdio>
#include  <iostream>
#include  <stdlib.h>
#include  <string.h>

using namespace std;

int data[50002];
int backsum[50002];


int main()
{
    int t,n,i,big,sum,tmp;
    scanf("%d", &t);
    while(t--)
    {
        memset(data, 0, sizeof(data));
        memset(backsum, 0, sizeof(backsum));
        big = 0;
        sum=0;
        tmp=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)      scanf("%d", &data[i]);
        for(i=n-1; i>=0; --i)
        {
            tmp+=data[i];
            backsum[i]=max(backsum[i], tmp);
            if(tmp<0)    tmp=0;
        }
        tmp=0;
        for(i=0; i<n-1; ++i)
        {
            tmp += data[i];
            sum = max(tmp, sum);
            if(tmp<0) tmp=0;
            big = max(sum+backsum[i+1], big);
        }
        printf("%d\n", big);
    }
}


/*
#include <stdio.h>

#define MAX_NUM (50000 + 10)
int num[MAX_NUM], l[MAX_NUM], r[MAX_NUM];

int main()
{

	int n, m, i, res, tmp;

	scanf ("%d", &n);
	while (n--)
	{
		scanf ("%d", &m);
		tmp = 0;
		res = -10001;
		for (i = 0; i < m; ++i)
		{
			scanf ("%d", &num[i]);
			tmp += num[i];
			if (tmp > res)
				res = tmp;
			if (tmp < 0)
				tmp = 0;
			l[i] = res;
		}
		res = -10001;
		tmp = 0;
		for (i = m - 1; i >= 0; --i)
		{
			tmp += num[i];
			if (tmp > res)
				res = tmp;
			if (tmp < 0)
				tmp = 0;
			r[i] = res;
		}
		res = l[0] + r[1];
		for (i = 0; i < m - 1; ++i)
		{
			tmp = l[i] + r[i + 1];
			if (tmp > res)
				res = tmp;
		}
		printf ("%d\n", res);
	}

	return 0;
}
**/
