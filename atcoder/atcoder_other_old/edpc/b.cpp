#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define orep(x,y) for(int x=1;x<=y;x++)
using namespace std;
#define getCost(x,y) abs(h[x] - h[y])
#define chmin(x,y) (x = min(x,y))
#define inf 1e9
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n)cin >> h[i];
    vector<int> dp(n);
    rep(i,n)dp[i] = inf;
    dp[0] = 0;
    rep(i,n){
        orep(j,k){
            if(i+j<n)chmin(dp[i+j],dp[i] + getCost(i+j,i));
        }
    }
    cout << dp[n-1] << endl;
}