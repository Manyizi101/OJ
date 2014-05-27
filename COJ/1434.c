#include   <stdio.h>
#include   <string.h>

int main()
{
    char a[1000];
    while (gets(a) &&a[0] != EOF)
    puts(a);
    return 0;
}
