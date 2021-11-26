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
using mint = modint998244353;
using P = pair<int,int>;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  int max = 3001;
  vector<mint> dp(max);
  dp[0] = 1;
  rep(i,n){
    vector<mint> sum(max);
    rep(j,max){
      if(j==0){
        sum[0] = dp[0];
        continue;
      }
      sum[j] = sum[j-1] + dp[j];
    }
    vector<mint> dp2(max);
    for(int j=a[i];j<=b[i];j++){
      dp2[j] = sum[j];
    }
    swap(dp2,dp);
  }
  mint ans = 0;
  rep(i,max)ans += dp[i];
  cout << ans.val() << endl;
}