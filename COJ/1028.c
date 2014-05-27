#include   <stdio.h>

int main()
{
    int n, i, j, ans = 0, key,b[100] = {0};
    char a[100];
    scanf("%d%s", &n, &a);
    for(i = 0; i < n; i++)
    {
        for(j = 97; j <= 122; j++)
        {
            if(a[i] == j)   b[j-97]+= 1;
        }
    }
    for(i = 0; i < 26; i++)
    {
        if(ans <= b[i])
        {
            ans = b[i];
            key = i;
        }
    }
    printf("%c", key+97);
    return 0;
}
