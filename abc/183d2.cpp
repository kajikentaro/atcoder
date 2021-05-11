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
const ll inf = 1e18;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];

    vector<ll> b(n);
    b[0] = a[0];
    rep(i,n){
        if(i==0)continue;
        b[i] = a[i] + b[i-1];
    }

    vector<ll> max_b(n);
    ll max_v= -inf;
    rep(i,n){
        chmax(max_v, b[i]);
        max_b[i] = max_v;
    }

    ll now = 0;
    ll ans = 0;
    rep(i,n){
        now += b[i];
        if(i < n-1){
            ll next_max = now + max_b[i];
            chmax(ans, next_max);
        }
        chmax(ans, now);
    }
    cout << ans << endl;
}
