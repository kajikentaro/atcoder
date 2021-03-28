#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define chmin(x,y) x = min(x,y)
#define inf 1e9
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,inf));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,m){
            chmin(dp[i+1][j], dp[i][j] + 1);
            chmin(dp[i][j+1], dp[i][j] + 1);
            if(a[i] == b[j])chmin(dp[i+1][j+1], dp[i][j]);
            else chmin(dp[i+1][j+1], dp[i][j] + 1);
        }
        chmin(dp[i][m], dp[i-1][m] + 1);
        chmin(dp[i][m], dp[i][m-1] + 1);
    }
    chmin(dp[n][m], dp[n-1][m] + 1);
    chmin(dp[n][m], dp[n][m-1] + 1);
    cout << dp[n][m] << endl;
}
       