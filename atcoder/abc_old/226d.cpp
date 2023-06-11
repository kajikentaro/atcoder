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
int gcd(int a,int b){
  if(a % b == 0)return b;
  return gcd(b,a%b);
}
int main(){
  int n;
  cin >> n;
  vector<P> cor(n);
  rep(i,n){
    cin >> cor[i].first >> cor[i].second;
  }
  set<P> magicpp;
  set<P> magicmp;
  set<P> magicpm;
  set<P> magicmm;
  int right,left,up,down;
  right = left = up = down = 0;
  rep(i,n){
    rep(j,n){
      if(i==j)continue;
      int x = cor[i].first - cor[j].first;
      int y = cor[i].second - cor[j].second;
      if(x == 0){
        if(y > 0)up = 1;
        if(y < 0)down = 1;
        continue;
      }
      if(y == 0){
        if(x > 0)right = 1;
        if(x < 0)left = 1;
        continue;
      }
      if(x < 0 && y < 0){
        x *= -1;
        y *= -1;
        int g = gcd(x,y);
        x /= g;
        y /= g;
        magicmm.emplace(x,y);
        continue;
      }
      if(x < 0){
        x *= -1;
        int g = gcd(x,y);
        x /= g;
        y /= g;
        magicmp.emplace(x,y);
        continue;
      }
      if(y < 0){
        y *= -1;
        int g = gcd(x,y);
        x /= g;
        y /= g;
        magicpm.emplace(x,y);
        continue;
      }
      int g = gcd(x,y);
      x /= g;
      y /= g;
      magicpp.emplace(x,y);
    }
  }
  ll ans = magicmm.size() + magicmp.size() + magicpm.size() + magicpp.size() + up + right + down + left;
  cout << ans << endl;
}