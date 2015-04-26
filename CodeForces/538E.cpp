#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1<<31;
using namespace std;

int gDary = 2;  
//全局函数指定多少分叉树，这里是5，代表5叉树。  
int heapDaryParent(int cIndex)  //cIndex 为C下标0开始  
{  
    return (cIndex-1)/gDary;  
}  
  
int heapDaryChild(int cIndex, int d)    //cIndex 为C下标0开始，d为第几个孩子从1开始  
{  
    return cIndex*gDary+d;  
}  
  
//找出当前节点和其孩子们的当中的最大值;  
//本人觉得是本人创造的非常妙的从daryHeapify函数中分离出来的功能函数。极大的简化了对本算法的理解。  
template<typename T>  
int daryMax(vector<T>& heap, int cIndex, int heapSize)  
{  
    T tempMax = heap[cIndex];  
    int childIndex = 0;  
    int tempIndex = cIndex;  
    for(int i = 1; i<=gDary; i++)  
    {  
        childIndex = heapDaryChild(cIndex, i);  
        if(childIndex<heapSize)  
        {  
            if(heap[childIndex]>tempMax)  
            {  
                tempMax = heap[childIndex];  
                tempIndex = childIndex;  
            }  
        }  
    }  
    return tempIndex;  
}  
  
//We assume cIndex's children have all been heapified, which is the key to make this algorithm work!!!  
//比之前的二叉树堆排序更加简洁明了点  
template<typename T>  
void daryHeapify(vector<T>& heap, int cIndex, int heapSize)  
{  
    if(cIndex<heapSize)  
    {  
        int tempIndex = daryMax(heap, cIndex, heapSize);  
        if(tempIndex != cIndex)  
        {  
            swap(heap[cIndex], heap[tempIndex]);  
            daryHeapify(heap, tempIndex, heapSize);   
        }  
    }  
}  
  
template<typename T>  
void buildMaxDaryHeap(vector<T>& heap)  
{  
    for(int i=(heap.size()-1)/gDary; i>=0; i--)  
        daryHeapify(heap, i, heap.size());  
}  
  
template<typename T>  
void daryHeapSort(vector<T>& heap)  
{  
    buildMaxDaryHeap(heap);  
    for(int i=heap.size()-1; i>0; i--)  
    {  
        swap(heap[0], heap[i]);  
        daryHeapify(heap, 0, i);  
    }  
}  
  
template<typename T>  
void heapPrint(const vector<T>& heap)  
{  
    for(auto x:heap)  
    {  
        cout<<x<<" ";  
    }  
    cout<<endl;  
}  
  
  
void test()  
{  
    //初始化数组  
    int a[5] = {1,5,4,3,2};  
    vector<int> heap(a, a+5);  
  
    //序列输出  
    cout<<"Befor build heap:\n";  
    heapPrint(heap);  
  
    //建立大顶堆后输出  
    buildMaxDaryHeap(heap);  
    cout<<"After build heap:\n";  
    heapPrint(heap);  
  
    //排序后  
    cout<<"After sort:\n";  
    daryHeapSort(heap);  
    heapPrint(heap);  
}  
  
int main()  
{  
    test();  
    return 0;  
}