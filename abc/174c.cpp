#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int func(){
    int k;
    cin >> k;
    int a = 7;
    int a0 = a % k;
    if(a0 == 0)return 1;
    int c = 1;
    set<int> done;
    while(1){
        c++;
        int b = (a * 10 + 7) % k;
        if(b == 0)return c;
        if(done.count(b))return -1;
        swap(a,b);
        done.emplace(b);
    }
}
int main(){
    cout << func() << endl;
}