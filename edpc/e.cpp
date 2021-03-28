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
#define inf 1e18
#define MAX 1e6
int main(){
    int N,W;
    cin >> N >> W;
    vector<int> w(N+1);
    vector<int> v(N+1);
    orep(i,N)cin >> w[i] >> v[i];
    vector<vector<ll>> dp(N+1,vector<ll>(MAX+1,inf));
    rep(i,N+1)dp[i][0] = 0;
    orep(i,N)orep(j,MAX){
        if(j - v[i] < 0){
            chmin(dp[i][j], dp[i-1][j]);
        }else{
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
        }
    }
    ll result = 0;
    rep(j,MAX){
        if(dp[N][j] == inf)continue;
        if(dp[N][j] <= W){
            result = j;
        }
    }
    cout << result << endl;
}
