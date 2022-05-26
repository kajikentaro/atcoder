#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
  int n,m,k;
  cin >> n >> m >> k;

  vector<vector<int>> dp(n+1, vector<int>(k+1));
  dp[0][0] = 1;
  int mod = 998244353;
  rep(i,n){
    rep(j, k+1){
      orep(p, m){
        if(j + p >= k+1)continue;
        dp[i+1][j+p] = (dp[i+1][j+p] + dp[i][j]) % mod; 
      }
    }
  }
  ll ans = 0;
  rep(i, k+1){
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << endl;
}