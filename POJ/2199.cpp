#include <cstdio>
#include <cmath>
using namespace std;

double up, mid, down, rate;
double cof[12];
int month[12];
int lastMon;
double total, temp;
int count;
int Case = 0;

int main()
{
    int i;
    scanf("%d", &count);
    while (count != -1)
    {
        Case++;
        for (i = 0; i < count; i++)
        {
            scanf("%d%lf", &month[i], &cof[i]);
        }
        scanf("%d%lf", &lastMon, &total);
        for (i = 0; i < count; i++)
        {
            month[i] = lastMon - month[i] + 1;
        }
        up = 2;
        down = 1;
        mid = (up + down) / 2;
        while ((mid - down) > 0.000001)
        {
            temp = 0;
            for (i = 0; i < count; i++)
            {
                temp += cof[i] * pow(mid, month[i]);
            }
            if (temp < total)
                down = mid;
            else
                up = mid;
            mid = (up + down) / 2;
        }
        printf("Case %d: %.5lf\n", Case, mid - 1);
        if (scanf("%d", &count) && count != -1)
        {
            printf("\n");
        }
    }
    return 0;
}