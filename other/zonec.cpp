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
ll calc(vector<vector<ll>> x){
    ll mi = inf;
    rep(i,5){
        ll ma = 0;
        rep(j,3){
            chmax(ma,x[j][i]);
        }
        chmin(mi, ma);
    }
    return mi;
}
int main(){
    int n;
    cin >> n;
    vector<vector<ll>> dp(3,vector<ll>(5,0));
    rep(i,n){
        vector<ll> input(5);
        rep(k,5)cin >> input[k];

        int idx = -1;
        ll ma = 0;
        {
            ll ca = calc({dp[0], dp[1], input});
            if(chmax(ma, ca))idx = 2;
            
            ca = calc({dp[0], dp[1], dp[2]});
            if(chmax(ma, ca))idx = -1;

            ca = calc({dp[1], dp[2], input});
            if(chmax(ma, ca))idx = 0;

            ca = calc({dp[2], dp[0], input});
            if(chmax(ma, ca))idx = 1;
        }
        if(idx == -1)continue;
        rep(k,5){
            dp[idx][k] = input[k];
        }
    }
    cout << calc(dp) << endl;
}
