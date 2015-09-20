#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#define pb push_back
#define debug puts("=====================");
#define inf (1 << 30)
#define eps 1e-12
using namespace std;
typedef long long ll;
list<char> l;
list<char> :: iterator it, pos, tmp, I;
const int N = 100000 + 100;
char s[N];
char str[N];
int len, sb;
int n, m, mode, has, C;
void Insert(char x) {
    int tot = l.size();
    if (mode == 1) {
        if (tot < m) {
            l.insert(it, x);
        }
    } else {
        if (it != l.end()) {
            *it = x;
            it++;
        } else {
			if (tot < m) l.insert(it, x);
        }
    }
}
void Left() {
    if (it != l.begin()) it--;
}
void Right() {
    if (it != l.end()) it++;
}
void Change() {
    mode ^= 1;
}
void Delete() {
    if (it != l.end()) {
        if (it != l.begin()) {
            tmp = it;
            tmp--;
            l.erase(it);
            it = ++tmp;
        } else {
            l.erase(it);
            it = l.begin();
        }
    }
}
void pos_Left() {
    if (pos != l.begin()) pos--, sb--;
}
void pos_Right() {
    if (pos != l.end()) pos++, sb++;
}
void pos_Delete() {
    if (pos != it) {
        if (sb < 0) {
			if (pos != l.begin()) {
				tmp = pos;
				tmp--;
				//cout<<*tmp<<endl;
				while(pos != it) {
					l.erase(pos);
					pos = tmp;
					pos++;
				}
				it = ++tmp;
			} else {
				while(pos != it) {
					l.erase(pos);
					pos = l.begin();
				}
				it = l.begin();
			}
        }
        else {
			if (it != l.begin()) {
				tmp = it;
				tmp--;
				while(pos != it) {
					l.erase(it);
					pos = tmp;
					pos++;
				}
				it = ++tmp;
			} else {
				while(pos != it) {
					l.erase(it);
					it = l.begin();
				}
				it = l.begin();
			}
        }
    }
}
void Back() {
    if (it == l.begin()) ;
    else {
        tmp = it;
        tmp--;
        l.erase(tmp);
    }
}
void Copy() {
    if (C == 0) {
        C = 1;
        pos = it;
    } else {
        C = 0;
        if (pos != it) {
            has = 1;
            len = 0;
            if (sb < 0) for (I = pos; I != it; I++) str[len++] = *I;
            else for (I = it; I != pos; I++) str[len++] = *I;
        } else has = 0;
    }
}
void Paste() {
    if (has) {
		//puts(str);
		if (len + l.size() > m) return ;
        for (int i = 0; i < len; i++) Insert(str[i]);
    }
}
void out() {
    if (l.size()) {
        for (I = l.begin(); I != l.end(); I++) putchar(*I);
        puts("");
    } else puts("NOTHING");
}
int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %s", &m, s);
        l.clear();
        it = l.begin();
        mode = 1, has = 0, C = 0;
        n = strlen(s);
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                if (C == 1) C = 0, it = pos;
                Insert(s[i]);
            } else {
                if (C == 0) {
                    sb = 0;
                    if (s[i] == 'L') Left();
                    if (s[i] == 'R') Right();
                    if (s[i] == 'S') Change();
                    if (s[i] == 'D') Delete();
                    if (s[i] == 'B') Back();
                    if (s[i] == 'C') Copy();
                    if (s[i] == 'V') Paste();
                } else {
                	//cout<<sb<<endl;
                    if (s[i] == 'L') pos_Left();
                    if (s[i] == 'R') pos_Right();
                    if (s[i] == 'C') Copy(), it = pos;
                    if (s[i] == 'D') C = 0, pos_Delete();
                    if (s[i] == 'S') C = 0, it = pos, Change();
                    if (s[i] == 'B') C = 0, it = pos, Back();
                    if (s[i] == 'V') C = 0, it = pos, Paste();
                }
            }
            //out();
        }
        out();
    }
    return 0;
}

