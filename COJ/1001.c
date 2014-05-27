#include  <stdio.h>

main()
{
    int apple[10];
    int height;
    int i, k = 0;
    int chair = 30;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &apple[i]);
    }
    scanf("%d", &height);
    for (i = 0; i < 10; i++)
    {
        if (apple[i] <= (height + chair))
        {
            k++;
        }
    }
    printf("%d", k);
    return 0;
}
