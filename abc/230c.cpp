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
  ll n,a,b,p,q,r,s;
  cin >> n >> a >> b >> p >> q >> r >> s;
  string line = "";
  ll height = q-p+1;
  ll width = s-r+1;
  rep(i,width)line += ".";
  vector<string> ans(height, line);
  ll r1 = max(1-a, 1-b);
  ll r2 = min(n-a, n-b);

  ll s1 = max(1-a, b-n);
  ll s2 = min(n-a, b-1);
  rep(i,height){
    rep(j,width){
      ll row = i + p;
      ll col = j + r;

      row -= a;
      col -= b;

      bool ok = false;
      if(row == col && r1 <= row && row <= r2)ok = true;
      if(row == -col && s1 <= row && row <= s2)ok = true;
      if(ok)ans[i][j] = '#';
    }
  }
  rep(i,height)cout << ans[i] << endl;
}