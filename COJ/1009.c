#include <stdio.h>

int main()
{
    int n, height[200] = {0};
    int i, j, man = 3, higher = 0, left = 0;
    scanf("%d", &n);
    int right = n-1;
    for(i = 0; i < n; i++)      scanf("%d", &height[i]);
    for(i = 1; i < n -1 ; i++)
    {
        if(height[i] > height[higher])  higher = i;
        if(height[i] < height[left] && i < n/2)    left = i;
    }
    for(j = n-1; j > 0; j--)
    {
        if(height[j] < height[right] && j > higher)   right = j;
    }
    for(i = left; i < higher; i++)
    {
        if (height[i] > height[left] && height[i] < height[higher])      man += 1;
    }
    for(i = right; i > higher; i--)
    {
        if (height[i] < height[higher] && height[i] > height[right])    man += 1;
    }
    printf("%d", n - man);
    return 0;
}
