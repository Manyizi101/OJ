#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
//getLength()������ȡ_num����
    int getLength(){
    	int x=_num;
    	int len=0;
    	while(x!=0||x%10!=0)
    	{
    		len++;
    		x/=10;
    	}
    	return len;
    }
public:
//Integer�๹�캯��
    Integer(int num){
    	_num=num;
    }
//��ת_num
    int inversed(){
    	int len = getLength();
    	int tmp=_num;
    	int ans=0;
    	for(int i=0;i<len;i++)
    	{
    		ans=ans*10+tmp%10;
    		tmp/=10;
    	}
    	return ans;
    }
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
}