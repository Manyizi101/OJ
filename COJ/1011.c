#include   <stdio.h>

int main()
{
    int N = 0, i = 0, j = 0, sum = 0;
    scanf("%d", &N);
    char name[20] = {"\0"};
    char key_name[20] = {"\0"};
    int QiMo, BanJi, LunWen, money = 0;
    int key_money = 0;
    char GanBu, XiBu;
    for (i = N; i > 0; i--)
    {
        scanf("%s %d %d %c %c %d", &name, &QiMo, &BanJi, &GanBu, &XiBu, &LunWen);
        money = 0;
        if (QiMo > 80 && LunWen >= 1)     money = money + 8000;
        if (QiMo > 85 && BanJi > 80)      money = money + 4000;
        if (QiMo > 90)          money = money + 2000;
        if (QiMo > 85 && XiBu == 'Y')      money = money + 1000;
        if (BanJi > 80 && GanBu == 'Y')     money = money + 850;
        if (money > key_money)
        {
            for(j = 0; j < 20; j++)
            {
                key_name[j] = name[j];
            }
            key_money = money;
        }
        sum += money;
    }
    printf("%s\n%d\n%d\n", key_name, key_money, sum);
    return 0;
}

    /*int N = 0, i = 0, j =0, sum = 0, key = 0;
    scanf("%d", &N);
    char name[N][20], Tep[20];
    int QiMo[N], BanJi[N], LunWen[N], money[N];
    char GanBu[N], XiBu[N];
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d %c %c %d", name[N], &QiMo[i], &BanJi[i], &GanBu[i], &XiBu[i], &LunWen[i]);
    }
    for (i = 0; i < N; i++)
    {
        money[i] = 0;
        if (QiMo[i] > 80 && LunWen[i] >= 1)     money[i] += 8000;
        if (QiMo[i] > 85 && BanJi[i] > 80)      money[i] += 4000;
        if (QiMo[i] > 90)          money[i] += 2000;
        if (QiMo[i] > 85 && XiBu[i] == 'Y')      money[i] += 1000;
        if (BanJi[i] > 80 && GanBu[i] == 'Y')     money[i] += 850;
        sum += money[i];
    }
    for (i = 0; i < N; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (money[i] < money[j])
            {
                key = money[i];
                money[i] = money[j];
                money[j] = key;
                Tep[20] = name[i][20];
                name[i][20] = name[j][20];
                name[j][20] = Tep[20];
            }
        }
    }
    printf("%s\n%d\n%d\n", name[0], money[0], sum);
    return 0;
    */
    /*用这段长长的注释来祭奠我悲剧的二维数组的首次尝试。。。。。。。。。。。。。。。。**/


