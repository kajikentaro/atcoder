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
  int q;
  cin >> q;
  set<int> se;
  int n = 1<<20;
  rep(i,n){
    se.insert(i);
  }
  map<int, ll> ma;
  rep(i,q){
    int t;
    ll x;
    cin >> t >> x;
    int xx = x % n;
    if(t == 1){
      auto s = se.lower_bound(xx);
      if(s == se.end()){
        s = se.lower_bound(0);
      }
      ma[*s] = x;
      se.erase(*s);
    }else{
      if(ma.count(xx) == 1){
        cout << ma[xx] << endl;
      }else{
        cout << -1 << endl;
      }
    }
  }
}