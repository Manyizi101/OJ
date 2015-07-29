int a[1000005] = {};
void pdec(int n)
{
    int num = n;
    for (int i = 1; prime[i]*prime[i] <= n; i++)
        if (n % prime[i] == 0)
        {
            n /= prime[i];
            while (n % prime[i] == 0) n /= prime[i];
            a[num]++;
            if (n == 1) break;
        }
    if (n > 1) a[num]++;
}