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
  int h,w;
  cin >> h >> w;
  vector<vector<int>> k(h,vector<int>(w));
  rep(i,h)rep(j,w)cin >> k[i][j];
  rep(i2,h)rep(i1,i2){
    //b << a
    rep(j2,w)rep(j1,j2){
      if(k[i1][j1] + k[i2][j2] <= k[i2][j1] + k[i1][j2])continue;
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
