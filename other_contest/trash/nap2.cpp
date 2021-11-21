#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
vector<vector<int>> dp;
int main(){
    int n,W;
    cin >> n >> W;
    dp.resize(n+1,vector<int>(W+1));
    vector<int> w(n);
    vector<int> v(n);
    rep(i,n)cin >> v[i] >> w[i];
    rep(i,n)rep(j,W+1){
        dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
        if(j+w[i] > W)continue;
        dp[i+1][j+w[i]] = max(dp[i][j] + v[i],dp[i+1][j+w[i]]);
    }
    rep(i,n+1){
        rep(j,W+1){
            printf("%3d ",dp[i][j]);
        }
        cout << endl;
    }
}