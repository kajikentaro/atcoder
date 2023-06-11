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
vector<int> p(110,0);
int check(int a){
    if(a <= 105 && a >= 0){
        return p[a];
    }else{
        return 0;
    }
}
int func(){
    int x,n;
    cin >> x >> n;
    rep(i,n){
        int in;
        cin >> in;
        p[in] = 1;
    }
    rep(i,110){
        if(check(x-i) == 0)return x-i;
        if(check(x+i) == 0)return x+i;
    }
    return 1/0;
}
int main(){
    cout << func() << endl;
}
