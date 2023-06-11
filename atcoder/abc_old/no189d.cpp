#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,n+1){
        if(i==0)continue;
        if(s[i-1] == "AND"){
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];
        }
        if(s[i-1] == "OR"){
            dp[i][1] = dp[i-1][0] + dp[i-1][1] * 2 ;
            dp[i][0] = dp[i-1][0];
        }
    }
    cout <<  dp[n][1] << endl;
}
