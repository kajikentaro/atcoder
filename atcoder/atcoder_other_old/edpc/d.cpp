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
int main(){
    int N,W;
    cin >> N >> W;
    vector<int> w(N);
    vector<int> v(N);
    rep(i,N)cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N+1,vector<ll>(W+1));
    orep(i,N)orep(j,W){
        if(j - w[i-1] < 0){
            chmax(dp[i][j],dp[i-1][j]);
            continue;
        }
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
    }
    cout << dp[N][W] << endl;
}