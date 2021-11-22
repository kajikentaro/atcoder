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
  return gcd(b, a%b);
}
int main(){
  int n;
  cin >> n;
  vector<P> input(n);
  rep(i,n)cin >> input[i].first >> input[i].second;
  rep(i,n){
    map<P,int> ma;
    rep(j,n){
      if(i == j)continue;
      int x = input[j].first - input[i].first;
      int y = input[j].second - input[i].second;
      int k = gcd(x,y);
      x /= k;
      y /= k;
      ma[P(x,y)]++;
    }
    ll gn = ma.size();
    ll ans = gn * (gn - 1) / 2;
    for(auto m : ma){
      ans *= m.second;
    }
  }
}