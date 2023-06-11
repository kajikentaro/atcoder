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
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  map<P,int> edge;
  rep(i,n)rep(j,i){
    if(x[i] == x[j]){
      if(y[i] < y[j])swap(y[i],y[j]);
      edge[P(y[i],y[j])]++;
    }
  }
  ll ans = 0;
  for(auto e : edge){
    int i = e.second;
    if(i >= 2){
      ans += (i) * (i-1) / 2;
    }
  }
  cout << ans << endl;
}