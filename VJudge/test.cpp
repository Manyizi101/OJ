#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
void solve(int x, set<int> &result) {
    int k, high, b2, a;
    int c, sum, b1;
    for (k = 1; k <= x; k *= 10) {
        high = x / k;
        c = high / 11;
        c *= k;
        b1 = high % 11;
        if ((b1 != 0 || c != 0) && b1 < 10) {
            b1 *= k;
            a = (x - b1 - 11 * c) / 2;
            if (2 * a + b1 + 11 * c == x)
                result.insert(a + b1 + c * 10);
        }
        b2 = high % 11 - 1;
        if ((b2 != 0 || c != 0) && b2 >= 0) {
            b2 *= k;
            int a2 = (x - b2 - 11 * c) / 2;
            if (x == 2 * a2 + b2 + 11 * c)
                result.insert(a2 + b2 + 10 * c);
        }
    }
}
int main() {
    int x, i;
    while (cin >> x, x) {
        set<int>result;
        //set结构不仅可以排序，而且可以去除重复的
        //下次要多多学习，总结！
        solve(x, result);
        if (result.empty()) {
            printf("No solution.\n");
        }
        else {
            set<int>::iterator it = result.begin();
            printf("%d", *it);
            while (++it != result.end())
                printf(" %d", *it);
            printf("\n");
        }
    }
    return 0;
}3