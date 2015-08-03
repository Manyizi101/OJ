#include <stdio.h>
#include <string.h>

int n;
char sb[205];
char stack[205];
int main()
{
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        int i;
        memset(stack, 0, sizeof(stack));
        gets(sb);
        int t = 0;
        int len = strlen(sb);
        for (i = 0; i < len; i ++)
        {
            if (sb[i] == '(' || sb[i] == '[')
            {
                stack[t] = sb[i];
                t ++;
            }
            if (sb[i] == ')')
            {
                if (stack[t - 1] == '(')
                {
                    stack[t - 1] = '\0';
                    t --;
                }
                else
                {
                    stack[t] = sb[i];
                    t ++;
                }
            }
            if (sb[i] == ']')
            {
                if (stack[t - 1] == '[')
                {
                    stack[t - 1] = '\0';
                    t --;
                }
                else
                {
                    stack[t] = sb[i];
                    t ++;
                }
            }
        }
        if (stack[0] == '\0')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}