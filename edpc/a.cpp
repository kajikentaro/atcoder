#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
#define getCost(x,y) abs(h[x] - h[y])
#define chmin(x,y) (x = min(x,y))
#define inf 1e9
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n)cin >> h[i];
    vector<int> dp(n);
    rep(i,n)dp[i] = inf;
    dp[0] = 0;
    rep(i,n){
        if(i+1<n)chmin(dp[i+1],getCost(i,i+1)+dp[i]);
        if(i+2<n)chmin(dp[i+2],getCost(i,i+2)+dp[i]);
    }
    cout << dp[n-1] << endl;
}