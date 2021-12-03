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
  ll n,w;
  cin >> n >> w;
  vector<pair<ll,ll>> c(n);
  rep(i,n)cin >> c[i].first >> c[i].second;
  sort(c.rbegin(), c.rend());
  ll ans = 0;
  rep(i,n){
    ll use  = min(c[i].second, w);
    ans += c[i].first * use;
    w -= use;
    if(w == 0)break;
  }
  cout << ans << endl;
}