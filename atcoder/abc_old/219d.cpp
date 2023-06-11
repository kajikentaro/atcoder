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
  int n,x,y;
  cin >> n >> x >> y;
  vector<vector<int>> dp(611,vector<int>(611,1e9));
  dp[0][0] = 0;
  int ans = 1e9;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    rrep(ca,301)rrep(cb,301){
      int c = dp[ca][cb];
      if(c == 1e9)continue;
      int na = ca + a;
      int nb = cb + b;
      int nc =  c + 1;
      if(na >= x && nb >= y){
        chmin(ans, nc);
      }
      chmin(dp[na][nb], nc);
    }
  }
  if(ans == 1e9){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}
