#include  <stdio.h>

int main()

{
    int school_time[7], mother_time[7], all_time[7] = {0};
    int day[] = {1, 2, 3, 4, 5, 6, 7};
    int i, j, key1, key2 = 0;
    for (i = 0; i < 7; i++) scanf("%d%d", &school_time[i], &mother_time[i]);
    for (i = 0; i < 7; i++) all_time[i] = school_time[i] + mother_time[i];
    for (i = 6; i  >= 0; i--)
        for (j = 0; j < i; j++)
        {
            if (all_time[i] < all_time[j])
            {
                key1 = all_time[i];
                all_time[i] = all_time[j];
                all_time[j] = key1;
                key2 = day[i];
                day[i] = day[j];
                day[j] = key2;
            }
        }
    if (all_time[6] > 8) printf("%d", day[6]);
    if (all_time[6] <= 8) printf("0");
    return 0;
}
