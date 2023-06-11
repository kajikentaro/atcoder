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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n)cin >> a[i];
  sort(a.rbegin(), a.rend());
  a.push_back(0);
  ll times = 1;
  ll ans = 0;
  rep(i,n){
    ll margin = a[i] - a[i+1];
    ll count = times * margin;
    if(k - count < 0){
      ll new_margin = k / times;
      ll new_count = times * new_margin;
      ll res = new_margin * (a[i] - new_margin) + new_margin * (new_margin + 1) / 2;
      res *= times;
      ans += res;

      k -= new_count;
      ans += (a[i] - new_margin) * k;
      break;
    }
    ll res = margin * (a[i] - margin)+ margin * (margin + 1) / 2;
    res *= times;
    ans += res;

    k -= count;
    times++;
  }
  cout << ans << endl;
}
