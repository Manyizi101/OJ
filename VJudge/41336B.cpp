#include  <stdio.h>
#include  <string.h>
#include  <iostream>
#include  <stdlib.h>

using namespace std;

int f[101000];

int main()
{
    int n,m,i;
    int mid, _max, _min;

    scanf("%d%d", &m,&n);
    _min=0;
    _max=0;
    for(i=0; i<m; i++)
    {
        scanf("%d", &f[i]);
        _max += f[i];
        if(f[i]> _min)
        {
            _min = f[i];
        }
    }

    while(_min < _max)
    {
        mid = (_min + _max)/2;
        int sum = 0, count =0;
        for(i=0; i<m; i++)
        {
            sum+=f[i];
            if(sum>mid)
            {
                count++;
                sum =f[i];
            }
        }
        if(count<n)
        {
            _max = mid;
        }
        else
        {
            _min = mid +1;
        }
    }
    printf("%d\n", _min);
    return 0;
}
