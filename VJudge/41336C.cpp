#include  <stdio.h>
#include  <math.h>

using namespace std;

double PI = acos(-1.0);
double r[10010];
double v[10010];

int main()
{
    int n,f,c;
    double left,mid,right;
    double sum;
    int i,t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&f);
        f++;
        left=mid=right=sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%lf", &r[i]);
            v[i]=r[i]*r[i]*PI;
            right+=v[i];
            if(v[i]>left)
                left=v[i];
        }
        left = left/f;
        right = right/f;

        while(left+0.00001<right)
        {
            mid = (left+right)/2;
            c=0;
            for(i=0; i<n; i++)
            {
                    c+=floor(v[i]/mid);
            }
            if(c<f)
            {
                right=mid;
            }
            else
            {
                left=mid;
            }
        }
        printf("%.4lf\n", left);
    }
    return 0;

}
