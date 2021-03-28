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
ll back(ll c){
    if(c == 0)return 1;
    if(c == 1)return 1;
    return c;
}
ll front2(ll c){
    if(c == 0)return 1;
    if(c == 1)return 1;
    return c;
}
ll front(ll b, ll c){
    ll notzero = front2(c);

    ll p = b * 2 ;

    return min(notzero, p);
}
int main(){
    ll b,c;
    cin >> b >> c;
    ll ans = 0;
    if(b <= 0){
        ans += back(c);
        if(b != 0)ans += front(-b,c-1);
    }else{
        ans += back(c - 1);
        ans += front(b,c);
    }
    cout << ans << endl;
}

