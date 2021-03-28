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
vector<vector<ll>> dp;
ll func(ll l, ll n){
    if(dp[l][n] != -1)return dp[l][n];
    if(l == n+1)return 1;
    if(l < n+1)return 0;
    if(n == 0)return 1;
    ll ans = 0;
    for(ll i=1;i<=l-1;i++){
        ans +=  func(l-i,n-1) ;
    }
    return dp[l][n] = ans;
}

int main(){
    dp.resize(220,vector<ll>(13,-1));
    ll l;
    cin >> l;
    cout << func(l,11) << endl;
}
