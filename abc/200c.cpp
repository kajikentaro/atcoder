#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
ll func(ll a,ll b){
    ll x,y;
    x = y = 1;
    rep(i,b){
        x *= (a - i);
        y *= (b - i);
    }
    return x / y;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> a(200);
    rep(i,n){
        ll t;
        cin  >> t;
        t %= 200;
        a[t]++;
    }
    ll ans = 0;
    rep(i,200){
        if(a[i] == 0)continue;
        if(a[i] == 1)continue;
        ans += func(a[i], 2);
    }
    cout << ans << endl;
    return 0;
}