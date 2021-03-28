#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
 
int in() {
  double x;
  cin >> x;
  x *= 10000;
  return round(x);
}
 
bool ok(ll dx, ll dy, ll z) {
  return dx*dx+dy*dy <= z*z;
}
ll f(ll x, ll y, ll z, ll lim) {
  int l = 0, r = 1;
  ll res = 0;
  int c = 0;
  for (int i = int(1e9)+50000; i >= lim; i -= 10000) {
    while (ok(x-l*10000,i-y,z)) --l;
    while (ok(r*10000-x,i-y,z)) ++r;
    ll debug = r-l-1;
    if(debug){
      cout << debug << endl;
      res += debug;
      c++;
      if(c==54733){
        int a;
        c--;
        c++;
      }
    }
  }
  return res;
}
vector<ll> debuglist;
ll f2(ll x, ll y, ll z, ll lim) {
  int l = 0, r = 1;
  ll res = 0;
  for (int i = int(1e9)+50000; i >= lim; i -= 10000) {
    while (ok(x-l*10000,i-y,z)) --l;
    while (ok(r*10000-x,i-y,z)) ++r;
    ll debug = r-l-1;
    if(debug){
      debuglist.push_back(debug);
        res += debug;
    }
  }
  rep(i,debuglist.size()){
    cout << debuglist[debuglist.size() - i - 1] << endl;
  }
  return res;
}
 
int main() {
  ll x = in();
  ll y = in();
  ll z = in();
  x %= 10000;
  y %= 10000;
  ll ans = f(x,y,z,10000);
  ans += f2(x,-y,z,0);
  cout << ans << endl;
  return 0;
}