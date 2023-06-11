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
ll calc(ll l, ll r, ll x){
  if(x<l)return l - x;
  if(r<x)return x - r;
  return 0;
}
int main(){
  int n;
  cin >> n;
  vector<ll> l(n);
  vector<ll> r(n);
  rep(i,n)cin >> l[i] >> r[i];
  ll wa = 1e16;
  ll ac = 0;
  while(wa - ac != 1){
    ll wj = (wa - ac) / 2;
    ll x_mi = 1e10;
    ll x_ma =-1e10;
    rep(i,n){
      chmin(x_mi, l[i]-wj);
      chmax(x_ma, r[i]+wj);
    }
    if(x_mi <= x_ma){
      ac = wj;
    }else{
      wa = wj;
    }
  }
}