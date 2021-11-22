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
ll gcd(ll x,ll y){
  if(x % y == 0){
    int minous = 1;
    if(x < 0)minous *= -1;
    if(y < 0)minous *= -1;
    return minous*y;
  }
  return gcd(y, x%y);
}
int main(){
  ll n;
  cin >> n;
  vector<P> input(n);
  rep(i,n)cin >> input[i].first >> input[i].second;
  ll ans = 0;
  rep(i,n)rep(j,i)rep(k,j){
    P a(input[j].first - input[k].first, input[j].second - input[k].second);
    P b(input[i].first - input[k].first, input[i].second - input[k].second);
    if(b.second < 0){
      b.second *= -1;
      b.first *= -1;
    }
    if(a.second < 0){
      a.second *= -1;
      a.first *= -1;
    }
    if(a.first*a.second*b.first*b.second == 0){
      if(a.first == 0 && b.first == 0)continue;
      if(a.second == 0 && b.second == 0)continue;
      ans++;
      continue;
    }
    ll a_gcd = gcd(a.first, a.second);
    ll b_gcd = gcd(b.first, b.second);
    a.first /= a_gcd;
    a.second /= a_gcd;
    b.first /= b_gcd;
    b.second /= b_gcd;
    if(a.first == b.first && b.second == a.second)continue;
    ans++;
  }
  cout << ans << endl;
}