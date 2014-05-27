#include <stdio.h>

int main()
{
    int budget[12] = {0};
    int remain = 0;
    int i = 0;
    int save = 0;
    for (i = 0; i < 12; i++)    scanf("%d", &budget[i]);
    for (i = 0; i < 12; i++)
    {
        remain = remain + 300 - budget[i];
        if (remain >= 400)
        {
            remain = remain - 400;
            save = save + 400;
        }
        if (remain >= 300)
        {
            remain = remain - 300;
            save = save + 300;
        }
        if (remain >= 200)
        {
            remain = remain - 200;
            save = save + 200;
        }
        if (remain >= 100)
        {
            remain = remain - 100;
            save = save + 100;
        }
        if (remain >= 0)
        {
            remain = remain - 0;
            save = save + 0;
        }
        if (remain < 0)
        {
            printf("-%d ", i+1);
            return 0;
        }
    }
    printf("%d", remain + (int)(save * 1.2));
    /*经过在地大OJ的测试，+1后，能够AC，但是代码是错的，不知何解。**/
    return 0;
}
