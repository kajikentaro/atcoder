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
vector<vector<int>> a;
vector<int> done;
void dfs(ll waza){
  if(done[waza] == 1)return;
  done[waza] = 1;
  for(auto aa : a[waza]){
    dfs(aa);
  }
}
int main(){
  ll n;
  cin >> n;
  vector<ll> t(n);
  a.resize(n);
  done.resize(n);
  rep(i,n){
    cin >> t[i];
    ll k;
    cin >> k;
    rep(j,k){
      ll ain;
      cin >> ain;
      ain--;
      a[i].push_back(ain);
    }
  }
  dfs(n-1);
  ll ans = 0;
  rep(i,n){
    if(done[i] == 1){
      ans += t[i];
    }
  }
  cout << ans << endl;
}
