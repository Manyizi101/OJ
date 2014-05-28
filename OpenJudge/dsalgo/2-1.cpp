#include  <iostream>

using namespace std;

struct LinkNode {
    int data;
    LinkNode * link;
};

class List {
private:
    LinkNode * first;
public:
    bool Insert(int i, int &x);


};

bool List::Insert(int i, int &x) {
    if(first == NULL || i==0) {
        LinkNode * newNode = new LinkNode(x);
        if(newNode == NULL) {cerr<<"存储分配错误\n"<<endl}
    }
}
int main()
{

}
