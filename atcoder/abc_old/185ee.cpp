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
    rep(i,n+1)rep(j,m+1){
        if(i-1 >= 0)chmin(dp[i][j], dp[i-1][j] + 1);
        if(j-1 >= 0)chmin(dp[i][j], dp[i][j-1] + 1);
        if(j-1 <0 || i-1 <0)continue;
        if(a[i-1] == b[j-1])chmin(dp[i][j], dp[i-1][j-1]);
        else chmin(dp[i][j], dp[i-1][j-1] + 1);
    }
    cout << dp[n][m] << endl;
}
       