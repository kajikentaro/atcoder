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
  ll n;
  cin >> n;
  vector<ll> prime;
  ll SEARCH_MAX = 1e6 + 10;
  vector<bool> tmp(SEARCH_MAX);
  for(ll i=2;i*i<=SEARCH_MAX;i++){
    if(tmp[i] == true)continue;
    for(ll j=i*2;j<SEARCH_MAX;j+=i){
      tmp[j] = true;
    }
  }
  rep(i,SEARCH_MAX){
    if(i<2)continue;
    if(tmp[i] == 0)prime.push_back(i);
  }

  ll s = prime.size();
  ll ans = 0;
  rep(i,s){
    ll p = prime[i];
    ll p3 = p * p * p;

    ll ac = 0;
    ll wa = s;
    while(wa - ac != 1){
      ll wj = (ac + wa) / 2;
      ll idx = wj - 1;
      if(prime[idx] <= n / p3 && prime[idx] < p){
        ac = wj;
      }else{
        wa = wj;
      }
    }
    ans += ac;
  }
  cout << ans << endl;
}