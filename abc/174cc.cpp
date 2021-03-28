#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int func(){
    int k;
    cin >> k;
    map<int,int> m;
    int p = 7 % k;
    m[p]++;
    for(int i=1;;i++){
        if(p== 0){
            return i;
        }
        p = (p * 10 + 7) % k;
        m[p]++;
        if(m[p]==2){
            return -1;
        }
    }
}
int main(){
    cout << func() << endl;
}
