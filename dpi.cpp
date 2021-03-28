#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<double> p(n);
    rep(i,n)cin >> p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1));
    dp[0][0] = 1;
    rep(i,n+1){
        if(i==0)continue;
        rep(j,n+1){
            dp[i][j] += dp[i-1][j] * (1 - p[i-1]);
            if(j-1 < 0)continue;
            dp[i][j] += dp[i-1][j-1] * p[i-1];
        }
    }
    double ans = 0;
    rep(on,n+1){
        int off = n - on;
        if(on > off){
            ans += dp[n][on];
        }
    }
    printf("%.10lf\n",ans);
}
