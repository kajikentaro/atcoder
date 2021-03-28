#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;   
#define rep(x,y) for(int x=0;x<y;x++)
#define orep(x,y) for(int x=1;x<=y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define inf 1e9
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n,vector<int>(3));
    rep(i,n)rep(j,3)dp[i][j] = -inf;
    vector<vector<int>> happy(n,vector<int>(3));
    rep(i,n)rep(j,3)cin >> happy[i][j];
    rep(i,3){
        dp[0][i] = happy[0][i];
    }
    rep(i,n){
        if(i==0)continue;
        rep(j,3){
            rep(k,3){
                if(k == j)continue;
                chmax(dp[i][k], dp[i-1][j] + happy[i][k]);
            }
        }
    }
    int happy_max = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    cout << happy_max << endl;
}
