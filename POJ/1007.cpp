#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class DNA
{
public:
    string seqDNA;
    int num;
};

int compare(const void *p1, const void *p2)
{
    return (((DNA *)p1)->num - ((DNA *)p2)->num);
}
int main()
{
    DNA *dna;
    int n, m, num, count(0);
    string listDNA;
    cin >> m >> n;
    dna = new DNA[n];
    while (count < n)
    {
        cin >> listDNA;
        num = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = i + 1; j < m; ++j)
            {
                if (listDNA.at(i) > listDNA.at(j))
                    ++num;
            }
        }
        dna[count].num = num;
        dna[count++].seqDNA = listDNA;
    }
    qsort(dna, n, sizeof(DNA), compare);
    for (int i = 0; i < n; ++i)
        cout << dna[i].seqDNA << endl;

    return 0;
}