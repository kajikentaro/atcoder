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
using mint = modint998244353;
using P = pair<int,int>;
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> l(k);
    vector<ll> r(k);
    rep(i,k){
        cin >> l[i] >> r[i];
        r[i]++;
    }
    vector<mint> dp(n);
    dp[0] = 1;
    dp[1] = -1;
    mint now = 0;
    rep(i,n){
        now += dp[i];
        rep(j,k){
            if(i + l[j] < n) dp[i + l[j]] += now;
            if(i + r[j] < n) dp[i + r[j]] -= now;
        }
    }
    mint c = 0;
    rep(i,n){
        c += dp[i];
    }
    cout << c.val() << endl;
}
