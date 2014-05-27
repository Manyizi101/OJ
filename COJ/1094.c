#include   <stdio.h>
#include   <string.h>

int main()
{
    int i, j, l , key=0;
    char a[100000];
    scanf("%s", &a);
    l = strlen(a);
    for(i = 0; i < l/2; i++)
    {
        if (a[i] == a[l-i-1])     key+=1;
    }
    if (key == l/2)  printf("Yes");
    else printf("No");
    return 0;
}
