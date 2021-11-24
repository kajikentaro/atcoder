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
ll dp[1024][8][2] = {};
int main(){
  string s;
  int t;
  cin >> s >> t;
  int n = s.size();

  dp[0][0][1] = 1;
  rep(i,n)rep(j,t+1)rep(k,2){
    //dp[桁][非ゼロ][strict]
    int x = s[i] - '0';
    rep(d,10){
      int ni = i + 1;
      int nj = j;
      int nk = 0;
      if(d != 0)nj = j + 1;
      if(k == 1){
        if(d == x)nk = 1;
        if(d > x)continue;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[n][t][0] + dp[n][t][1] << endl;
}