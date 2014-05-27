#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int maxn = 100000 + 10;

int main()
{
    int T, N, i, j, h, w;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        vector<pii> A, B;
        for(i = 0; i < N; i++)
        {
            scanf("%d%d", &h, &w);
            A.push_back(make_pair(h, w));
        }
        for(i = 0; i < N; i++)
        {
            scanf("%d%d", &h, &w);
            B.push_back(make_pair(h, w));
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int cnt = 0;
        multiset<int> s;
        s.clear();
        for(i = 0, j = 0; i < N; i++)
        {
            while(j < N && A[i].first >= B[j].first) s.insert(B[j++].second);
            if(!s.empty())
            {
                multiset<int>::iterator p = s.upper_bound(A[i].second);
                if(p != s.begin())
                {
                    s.erase(--p);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
