#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define orep(x,y) for(int x=1;x<=y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define mint modint1000000007
#define ll long long
using namespace std;
using namespace atcoder;   
tuple<ll,ll,ll> gcd(ll a, ll b){
    ll x,y,r;
    if(b == 0) return {1, 0, a};
    tie(x,y,r) = gcd(b, a % b);
    return {y, x + y * (-a / b), r};
}
vector<ll> ans;
void solve(){
    ll n,s,k;
    cin >> n >> s >> k;
    ll x,y,g;
    tie(x,y,g) = gcd(k,n);
    if(s%g != 0){
        ans.push_back(-1);
        return;
    }
    if(g == 1){
        ans.push_back(((-s * x % n) + n) % n );
        return;
    }
    n /= g;
    s /= g;
    k /= g;
    ans.push_back(((-s * x % n) + n) % n );
}
int main(){
    int t;
    cin >> t;
    rep(i,t)solve();
    rep(i,t)cout << ans[i] << endl;
}
