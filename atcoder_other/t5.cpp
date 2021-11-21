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
int main(){
    #define int ll
    int n,b,k;
    cin >> n >> b >> k;
    vector<int> c(k);
    rep(i,k)cin >> c[i];

    vector<vector<mint>> dp(n+1,vector<mint>(b));
    dp[0][0] = 1;
    rep(i,n){
        //i桁目
        rep(j,k){
            //c[j]を選択
            rep(l,b){
                //dp[i+1][l]の倍数それぞれについて
                dp[i+1][(l * 10 + c[j]) % b] += dp[i][l];
            }
        }
    }
    cout << dp[n][0].val() << endl;
}
