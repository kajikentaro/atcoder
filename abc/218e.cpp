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
  int n,m;
  cin >> n >> m;
  vector<pair<int,P>> path;
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    path.emplace_back(c,P(a,b));
  }
  sort(path.begin(), path.end());
  dsu uf(n);
  ll ans = 0;
  rep(i,m){
    if(path[i].second.first == path[i].second.second){
      ans += max(0, path[i].first);
      continue;
    }
    if(path[i].first <= 0){
      uf.merge(path[i].second.first, path[i].second.second);
      continue;
    }
    if(uf.same(path[i].second.first, path[i].second.second)){
      ans += path[i].first;
    }else{
      uf.merge(path[i].second.first, path[i].second.second);
    }
  }
  cout << ans << endl;
}